#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

class Album {
private:
    string artist;
    string title;
    int number_of_songs;
    int year;
    int downloads;

public:
    Album(string a, string t, int n, int y, int d) : artist(a), title(t), number_of_songs(n), year(y), downloads(d) {}

    void display() const {
        cout << "Artist: " << artist << "\n"
            << "Title: " << title << "\n"
            << "Number of songs: " << number_of_songs << "\n"
            << "Year: " << year << "\n"
            << "Downloads: " << downloads << "\n\n";
    }
};

void loadAndDisplayAlbums() {
    const string filename = "Data.txt";
    ifstream file(filename);
    if (!file) {
        cerr << "Error opening file.\n";
        return;
    }
    else {
        cout << "File opened successfully.\n";
    }

    vector<Album> albums;
    string title, artist;
    int number_of_songs, year, downloads;

    while (file >> ws && getline(file, title, ',') && getline(file, artist, ',') && file >> number_of_songs >> year >> downloads) {
        albums.emplace_back(artist, title, number_of_songs, year, downloads);
    }

    for (const Album& album : albums) {
        album.display();
    }
}

int main() {
    loadAndDisplayAlbums();
    return 0;
}
