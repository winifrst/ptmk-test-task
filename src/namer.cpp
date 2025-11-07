#include "namer.h"

#include <string>
#include <vector>

const std::vector<std::string> &Namer::maleFirstNames() {
  static const std::vector<std::string> data = {
      "Alexander", "Alexey",    "Andrey",     "Anton",     "Artyom",
      "Boris",     "Vadim",     "Valentin",   "Valery",    "Vasily",
      "Victor",    "Vitaly",    "Vladimir",   "Vladislav", "Vyacheslav",
      "Gennady",   "Georgy",    "Grigory",    "Daniel",    "Denis",
      "Dmitry",    "Evgeny",    "Egor",       "Ivan",      "Igor",
      "Ilya",      "Kirill",    "Konstantin", "Leonid",    "Maxim",
      "Mark",      "Matvey",    "Mikhail",    "Nikita",    "Nikolay",
      "Oleg",      "Pavel",     "Peter",      "Roman",     "Ruslan",
      "Sergey",    "Stanislav", "Stepan",     "Timofey",   "Fedor",
      "Yuri",      "Yaroslav"};

  return data;
}

const std::vector<std::string> &Namer::femaleFirstNames() {
  static const std::vector<std::string> data = {
      "Alexandra", "Alena",     "Alina",     "Alice",     "Alla",
      "Anastasia", "Angelina",  "Anna",      "Valentina", "Valeria",
      "Varvara",   "Vera",      "Veronika",  "Victoria",  "Galina",
      "Daria",     "Diana",     "Eva",       "Evgenia",   "Ekaterina",
      "Elena",     "Elizaveta", "Zhanna",    "Zlata",     "Irina",
      "Karina",    "Kira",      "Ksenia",    "Larisa",    "Lidia",
      "Lyubov",    "Lyudmila",  "Margarita", "Marina",    "Maria",
      "Nadezhda",  "Natalia",   "Nika",      "Nina",      "Oksana",
      "Olesya",    "Olga",      "Polina",    "Raisa",     "Regina",
      "Rita",      "Svetlana",  "Sofia",     "Tamara",    "Tatyana",
      "Uliana",    "Yulia",     "Yana"};

  return data;
}

const std::vector<std::string> &Namer::maleMiddletNames() {
  static const std::vector<std::string> data = {
      "Alexandrovich",  "Alexeevich",     "Andreevich",      "Antonovich",
      "Artyomovich",    "Borisovich",     "Vadimovich",      "Valentinovich",
      "Valeryevich",    "Vasilyevich",    "Victorovich",     "Vitalyevich",
      "Vladimirovich",  "Vladislavovich", "Vyacheslavovich", "Gennadyevich",
      "Georgievich",    "Grigoryevich",   "Danilovich",      "Denisovich",
      "Dmitrievich",    "Evgenyevich",    "Egorovich",       "Ivanovich",
      "Igorevich",      "Ilyich",         "Kirillovich",     "Konstantinovich",
      "Leonidovich",    "Maximovich",     "Markovich",       "Matveyevich",
      "Mikhailovich",   "Nikolaevich",    "Olegovich",       "Pavlovich",
      "Petrovich",      "Romanovich",     "Ruslanovich",     "Sergeevich",
      "Stanislavovich", "Stepanovich",    "Timofeevich",     "Fedorovich",
      "Yuryevich",      "Yaroslavovich"};

  return data;
}

const std::vector<std::string> &Namer::femaleMiddletNames() {
  static const std::vector<std::string> data = {
      "Alexandrovna",  "Alexeevna",     "Andreevna",      "Antonovna",
      "Artyomovna",    "Borisovna",     "Vadimovna",      "Valentinovna",
      "Valeryevna",    "Vasilyevna",    "Victorovna",     "Vitalyevna",
      "Vladimirovna",  "Vladislavovna", "Vyacheslavovna", "Gennadyevna",
      "Georgievna",    "Grigoryevna",   "Danilovna",      "Denisovna",
      "Dmitrievna",    "Evgenyevna",    "Egorovna",       "Ivanovna",
      "Igorevna",      "Ilyinichna",    "Kirillovna",     "Konstantinovna",
      "Leonidovna",    "Maximovna",     "Markovna",       "Matveyevna",
      "Mikhailovna",   "Nikolaevna",    "Olegovna",       "Pavlovna",
      "Petrovna",      "Romanovna",     "Ruslanovna",     "Sergeevna",
      "Stanislavovna", "Stepanovna",    "Timofeevna",     "Fedorovna",
      "Yuryevna",      "Yaroslavovna"};

  return data;
}

const std::vector<std::vector<std::string>> &Namer::maleLastNames() {
  static const std::vector<std::vector<std::string>> data = {
      // A (0)
      {"Abramov", "Alekseev", "Andreev", "Antonov", "Arhipov", "Afanasiev",
       "Akhmatov", "Aksakov", "Amosov", "Anisimov"},

      // B (1)
      {"Baranov", "Belov", "Belyaev", "Bogdanov", "Borisov", "Bulanov",
       "Burkov", "Butuzov", "Bykov", "Bragin"},

      // C (2)
      {"Chernov", "Chernyshev", "Chabanov", "Chekhov", "Cherkasov",
       "Chistyakov", "Chudov", "Chulkov", "Chupin", "Churkin"},

      // D (3)
      {"Danilov", "Davydov", "Demidov", "Denisov", "Dmitriev", "Dobrov",
       "Dorofeev", "Drozdov", "Dubinin", "Durov"},

      // E (4)
      {"Egorov", "Efimov", "Ermakov", "Evdokimov", "Ezhov", "Eliseev",
       "Emelyanov", "Erokhin", "Efremov", "Esenin"},

      // F (5)
      {"Fedorov", "Filippov", "Fomin", "Frolov", "Fetisov", "Filatov", "Fadeev",
       "Feoktistov", "Firsov", "Fokin"},

      // G (6)
      {"Gavrilov", "Galkin", "Gerasimov", "Golubev", "Gorbachev", "Grigoriev",
       "Gromov", "Gusev", "Guryev", "Golovin"},

      // H (7)
      {"Haritonov", "Hlebnikov", "Holmov", "Hudakov", "Hromov", "Hranov",
       "Hitrov", "Homyakov", "Hovanov", "Hramov"},

      // I (8)
      {"Ivanov", "Ignatiev", "Ilyin", "Isaev", "Inozemtsev", "Istratov",
       "Ishutin", "Ivolgjin", "Ikonnikov", "Ippolitov"},

      // J (9)
      {"Jukov", "Juravlev", "Jdanov", "Jilin", "Jivotov", "Jmurov", "Jurov",
       "Jukovskiy", "Jiglov", "Jivago"},

      // K (10)
      {"Kuznetsov", "Kozlov", "Karpov", "Krylov", "Komarov", "Kiselev",
       "Kovalev", "Klimov", "Kolesnikov", "Kotov"},

      // L (11)
      {"Lebedev", "Lobanov", "Lukin", "Lysenko", "Lavrov", "Lazarev", "Loginov",
       "Lvov", "Lyapunov", "Larionov"},

      // M (12)
      {"Mikhailov", "Morozov", "Maximov", "Markov", "Makarov", "Matveev",
       "Mironov", "Medvedev", "Melnikov", "Mishin"},

      // N (13)
      {"Nikolaev", "Nikitin", "Nazarov", "Naumov", "Nekrasov", "Noskov",
       "Novikov", "Nuriev", "Nevsky", "Nikonov"},

      // O (14)
      {"Orlov", "Osipov", "Ovsyannikov", "Obolensky", "Olenin", "Orekhov",
       "Orlovsky", "Ostrovsky", "Ozernov", "Odoevsky"},

      // P (15)
      {"Petrov", "Popov", "Pavlov", "Polyakov", "Prokhorov", "Ponomarev",
       "Potapov", "Pestov", "Pugachev", "Putilin"},

      // Q (16)
      {"Quintova", "Qvyatkovskaya", "Qvasnikova", "Qvitko", "Qvitsinskaya",
       "Qvorova", "Qvyat", "Qvirinova", "Qvyatkina", "Qvashnina"},

      // R (17)
      {"Romanov", "Ryabov", "Rybakov", "Rogov", "Rusakov", "Rumyantsev",
       "Razin", "Rodionov", "Rostov", "Rjevsky"},

      // S (18)
      {"Smirnov", "Sokolov", "Stepanov", "Sorokin", "Savin", "Semyonov",
       "Sergeev", "Sidorov", "Solovyov", "Suvorov"},

      // T (19)
      {"Tarasov", "Tikhonov", "Timofeev", "Titov", "Tretyakov", "Trofimov",
       "Tumanov", "Turgeniev", "Tkachev", "Tsvetkov"},

      // U (20)
      {"Ushakov", "Ustinov", "Uvarov", "Urusov", "Ukhov", "Ulyanov", "Umov",
       "Usov", "Uglov", "Ukolov"},

      // V (21)
      {"Vasilyev", "Vinogradov", "Volkov", "Vorobiev", "Vladimirov", "Vlasov",
       "Voronin", "Vishnevsky", "Vakhrushev", "Vetrov"},

      // W (22) - для полноты алфавита
      {"Woronov", "Wolkoff", "Wassiliev", "Wladimirov", "Wolkow", "Woronin",
       "Wassilieff", "Wolkonsky", "Woronzov", "Wolkonski"},

      // X (23) - для полноты алфавита
      {"Xenofontov", "Xruschev", "Xvorostinin", "Xilkov", "Xmelnitsky",
       "Xvostov", "Xitrovo", "Xrapovitsky", "Xandrov", "Xitrovo"},

      // Y (24)
      {"Yakovlev", "Yudin", "Yurasov", "Yuriev", "Yushkov", "Yefremov",
       "Yermolaev", "Yeltsin", "Yevseev", "Yazykov"},

      // Z (25)
      {"Zaitsev", "Zakharov", "Zverev", "Zhukov", "Zolotov", "Zimin", "Zorin",
       "Zubov", "Zykov", "Znamensky"}};

  return data;
}

const std::vector<std::vector<std::string>> &Namer::femaleLastNames() {
  static const std::vector<std::vector<std::string>> data = {
      // A (0)
      {"Abramova", "Alekseeva", "Andreeva", "Antonova", "Arhipova",
       "Afanasieva", "Akhmatova", "Aksakova", "Amosova", "Anisimova"},

      // B (1)
      {"Baranova", "Belova", "Belyaeva", "Bogdanova", "Borisova", "Bulanova",
       "Burkova", "Butuzova", "Bykova", "Bragina"},

      // C (2)
      {"Chernova", "Chernysheva", "Chabanova", "Chekhova", "Cherkasova",
       "Chistyakova", "Chudova", "Chulkova", "Chupina", "Churkina"},

      // D (3)
      {"Danilova", "Davydova", "Demidova", "Denisova", "Dmitrieva", "Dobrova",
       "Dorofeeva", "Drozdova", "Dubininа", "Durova"},

      // E (4)
      {"Egorova", "Efimova", "Ermakova", "Evdokimova", "Ezhova", "Eliseeva",
       "Emelyanova", "Erokhina", "Efremova", "Esenina"},

      // F (5)
      {"Fedorova", "Filippova", "Fomina", "Frolova", "Fetisova", "Filatova",
       "Fadeeva", "Feoktistova", "Firsova", "Fokina"},

      // G (6)
      {"Gavrilova", "Galkina", "Gerasimova", "Golubeva", "Gorbacheva",
       "Grigorieva", "Gromova", "Guseva", "Guryeva", "Golovina"},

      // H (7)
      {"Haritonova", "Hlebnikova", "Holmova", "Hudakova", "Hromova", "Hranova",
       "Hitrova", "Homyakova", "Hovanova", "Hramova"},

      // I (8)
      {"Ivanova", "Ignatieva", "Ilyina", "Isaeva", "Inozemtseva", "Istratova",
       "Ishutina", "Ivolgina", "Ikonnikova", "Ippolitova"},

      // J (9)
      {"Jukova", "Juravleva", "Jdanova", "Jilina", "Jivotova", "Jmurova",
       "Jurova", "Jukovskaya", "Jiglova", "Jivago"},

      // K (10)
      {"Kuznetsova", "Kozlova", "Karpova", "Krylova", "Komarova", "Kiseleva",
       "Kovaleva", "Klimova", "Kolesnikova", "Kotova"},

      // L (11)
      {"Lebedeva", "Lobanova", "Lukina", "Lysenko", "Lavrova", "Lazareva",
       "Loginova", "Lvova", "Lyapunova", "Larionova"},

      // M (12)
      {"Mikhailova", "Morozova", "Maximova", "Markova", "Makarova", "Matveeva",
       "Mironova", "Medvedeva", "Melnikova", "Mishina"},

      // N (13)
      {"Nikolaeva", "Nikitina", "Nazarova", "Naumova", "Nekrasova", "Noskova",
       "Novikova", "Nurieva", "Nevskaya", "Nikonova"},

      // O (14)
      {"Orlova", "Osipova", "Ovsyannikova", "Obolenskaya", "Olenina",
       "Orekhova", "Orlovskaya", "Ostrovskaya", "Ozernova", "Odoevskaya"},

      // P (15)
      {"Petrova", "Popova", "Pavlova", "Polyakova", "Prokhorova", "Ponomareva",
       "Potapova", "Pestova", "Pugacheva", "Putilina"},

      // Q (16)
      {"Quintov", "Kvyatkovsky", "Kvasnikov", "Kvitko", "Kvitsinsky", "Kvorov",
       "Kvyat", "Kvirinov", "Kvyatkin", "Kvashnin"},

      // R (17)
      {"Romanova", "Ryabova", "Rybakova", "Rogova", "Rusakova", "Rumyantseva",
       "Razina", "Rodionova", "Rostova", "Rjevskaya"},

      // S (18)
      {"Smirnova", "Sokolova", "Stepanova", "Sorokina", "Savina", "Semyonova",
       "Sergeeva", "Sidorova", "Solovyova", "Suvorova"},

      // T (19)
      {"Tarasova", "Tikhonova", "Timofeeva", "Titova", "Tretyakova",
       "Trofimova", "Tumanova", "Turgenieva", "Tkacheva", "Tsvetkova"},

      // U (20)
      {"Ushakova", "Ustinova", "Uvarova", "Urusova", "Ukhova", "Ulyanova",
       "Umova", "Usova", "Uglova", "Ukolova"},

      // V (21)
      {"Vasilyeva", "Vinogradova", "Volkova", "Vorobieva", "Vladimirova",
       "Vlasova", "Voronina", "Vishnevskaya", "Vakhrusheva", "Vetrova"},

      // W (22)
      {"Woronova", "Wolkoffa", "Wassilieva", "Wladimirova", "Wolkowa",
       "Woronina", "Wassilieffa", "Wolkonskaya", "Woronzova", "Wolkonskaya"},

      // X (23)
      {"Xenofontova", "Xruscheva", "Xvorostinina", "Xilkova", "Xmelnitskaya",
       "Xvostova", "Xitrova", "Xrapovitskaya", "Xandrova", "Ximaeva"},

      // Y (24)
      {"Yakovleva", "Yudina", "Yurasova", "Yurieva", "Yushkova", "Yefremova",
       "Yermolaeva", "Yeltsina", "Yevseeva", "Yazykova"},

      // Z (25)
      {"Zaitseva", "Zakharova", "Zvereva", "Zhukova", "Zolotova", "Zimina",
       "Zorina", "Zubova", "Zykova", "Znamenskaya"}};

  return data;
}

std::string Namer::getMaleFirstName(size_t index) {
  const auto &names = maleFirstNames();

  return names[index % names.size()];
}

std::string Namer::getFemaleFirstName(size_t index) {
  const auto &names = femaleFirstNames();

  return names[index % names.size()];
}

std::string Namer::getMaleMiddleName(size_t index) {
  const auto &names = maleMiddletNames();

  return names[index % names.size()];
}

std::string Namer::getFemaleMiddleName(size_t index) {
  const auto &names = femaleMiddletNames();

  return names[index % names.size()];
}

std::string Namer::getMaleLastName(char letter, size_t index) {
  int i = (letter - 'A') % 26;
  const auto &names = maleLastNames();

  return names[i][index % names[i].size()];
}

std::string Namer::getFemaleLastName(char letter, size_t index) {
  int i = (letter - 'A') % 26;
  const auto &names = femaleLastNames();

  return names[i][index % names[i].size()];
}

std::vector<std::string> Namer::generateLastNamesForLetter(char letter,
                                                           bool male) {
  std::vector<std::string> result;
  result.reserve(100);
  for (int i = 0; i < 100; ++i) {
    result.push_back(male ? getMaleLastName(letter, i)
                          : getFemaleLastName(letter, i));
  }
  return result;
}
