class Solution {
public:
  string reformatDate(string date) {
    map<string, string> mp = {{"Jan", "01"}, {"Feb", "02"}, {"Mar", "03"},
                              {"Apr", "04"}, {"May", "05"}, {"Jun", "06"},
                              {"Jul", "07"}, {"Aug", "08"}, {"Sep", "09"},
                              {"Oct", "10"}, {"Nov", "11"}, {"Dec", "12"}};

    if (date.size() == 12)
      date = '0' + date;
    return date.substr(9, 4) + '-' + mp[date.substr(5, 3)] + '-' +
           date.substr(0, 2);
  }
};
