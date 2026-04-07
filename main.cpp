#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>

using namespace std;

struct Student {
    string id;
    string name;
    int score;
    int insert_order;
};

int main() {
    // Optimize standard I/O operations for performance
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<Student> students;
    unordered_map<string, int> id_to_index;
    unordered_map<string, int> name_to_index;
    int insert_counter = 0;

    vector<Student> sorted_by_id;
    vector<Student> sorted_by_score;
    bool id_sorted = false;
    bool score_sorted = false;

    int cmd;
    while (cin >> cmd) {
        if (cmd == 1) {
            string id, name;
            int score;
            cin >> id >> name >> score;
            if (id_to_index.count(id)) {
                cout << "FAILED\n";
            } else {
                id_to_index[id] = students.size();
                name_to_index[name] = students.size();
                students.push_back({id, name, score, insert_counter++});
                id_sorted = false;
                score_sorted = false;
                cout << "SUCCESS\n";
            }
        } else if (cmd == 2) {
            for (const auto& s : students) {
                cout << s.id << " " << s.name << " " << s.score << "\n";
            }
        } else if (cmd == 3) {
            string id;
            cin >> id;
            if (id_to_index.count(id)) {
                const auto& s = students[id_to_index[id]];
                cout << s.id << " " << s.name << " " << s.score << "\n";
            }
        } else if (cmd == 4) {
            string name;
            cin >> name;
            if (name_to_index.count(name)) {
                const auto& s = students[name_to_index[name]];
                cout << s.id << " " << s.name << " " << s.score << "\n";
            }
        } else if (cmd == 5) {
            if (!id_sorted) {
                sorted_by_id = students;
                sort(sorted_by_id.begin(), sorted_by_id.end(), [](const Student& a, const Student& b) {
                    return a.id < b.id;
                });
                id_sorted = true;
            }
            for (const auto& s : sorted_by_id) {
                cout << s.id << " " << s.name << " " << s.score << "\n";
            }
        } else if (cmd == 6) {
            if (!score_sorted) {
                sorted_by_score = students;
                sort(sorted_by_score.begin(), sorted_by_score.end(), [](const Student& a, const Student& b) {
                    if (a.score != b.score) {
                        return a.score > b.score;
                    }
                    return a.insert_order < b.insert_order;
                });
                score_sorted = true;
            }
            for (const auto& s : sorted_by_score) {
                cout << s.id << " " << s.name << " " << s.score << "\n";
            }
        } else if (cmd == 7) {
            cout << "END\n";
            break;
        }
    }

    return 0;
}
