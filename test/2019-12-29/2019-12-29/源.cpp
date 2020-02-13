/*
 * ����libpcapʵ��ץ��������
 * pcap_demo.c
 * Created on: Oct 27, 2016
 * Author: zhangming
 */
#include <stdio.h>
#include <string.h>
#include <pcap.h>

void packet_handler(u_char *user, const struct pcap_pkthdr *pkt_header, const u_char *pkt_data)
{
	pcap_dump(user, pkt_header, pkt_data);// ������ݵ��ļ�
	printf("a packet with length of [%d]\n", pkt_header->len);// ��ӡץ���İ��ĳ���
}

int main(int argc, char *argv[])
{
	pcap_t *handle;                 // �Ự���

	char errbuf[PCAP_ERRBUF_SIZE]; // �洢������Ϣ���ַ���

	bpf_u_int32 mask;               //�������������
	bpf_u_int32 net;                //������IP��ַ

	struct bpf_program filter;      //�Ѿ�����õĹ�����
	char filter_app[] = "port 80";  //BPF���˹���,��tcpdumpʹ�õ���ͬһ�ֹ��˹���

	/* ̽���豸������ */
	char *dev;                      //ָ����Ҫ��ץ�����豸 ������linux�µ������豸eth0��lo�ֱ��������ͱ��ػ���
	dev = pcap_lookupdev(errbuf);   //���ص�һ���Ϸ����豸����������eth0
	pcap_lookupnet(dev, &net, &mask, errbuf); //���ؽӿڵ�����net������mask
	//dev = "lo";                   //�����Ҫץȡ���ص����ݰ���������˱��ʽΪhost localhost��ʱ�����ֱ��ָ��

	/* �Ի���ģʽ�򿪻Ự */
	handle = pcap_open_live(dev, BUFSIZ, 1, 0, errbuf);

	/* ���벢Ӧ�ù����� */
	pcap_compile(handle, &filter, filter_app, 0, net);
	pcap_setfilter(handle, &filter);

	/* ��������ļ� */
	pcap_dumper_t* out_pcap;
	out_pcap = pcap_dump_open(handle, "/home/zhangming/pack.pcap");

	/* �ػ�30���� */
	pcap_loop(handle, 30, packet_handler, (u_char *)out_pcap);

	/* ˢ�»����� */
	pcap_dump_flush(out_pcap);

	/* �ر���Դ */
	pcap_close(handle);
	pcap_dump_close(out_pcap);

	return(0);
}