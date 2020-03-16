class Solution {
  public:
    // Parameters:
    //        numbers:     an array of integers
    //        length:      the length of array numbers
    //        duplication: (Output) the duplicated number in the array number
    // Return value:       true if the input is valid, and there are some duplications in the array number
    //                     otherwise false
    bool duplicate(int numbers[], int length, int* duplication) {
      if(length < 2)
      {
        *duplication = -1;
        return false;
      }
      else if(length == 2)
      {
        if(numbers[0] == numbers[1])
        {
          *duplication = numbers[0];
          return true;
        }
        else 
        {
          *duplication = -1;
          return false;
        }
      }
      for(int i = 0;i < length;i++)
      {
        for(int j = i + 1;j < length;j++)
        {
          if(numbers[i] == numbers[j])
          {
            *duplication = numbers[i];
            return true;
          }
        }
      }
      *duplication = -1;
      return false;
    }
};
}
}
}
}
}
}
}
}
}
