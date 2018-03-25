#ifndef H_INFO
#define H_INFO

class Info
{
public:
	Info();
	Info(int score, int beginTime);
	const int& getScore() const;
	void score(const int& score);
	const int& getPlayerHealth() const;
	void playerHealth(const int& playerHealth);
	void currentTime(const int& currentTime);
	const int& getTime() const;
private:
	int score_;
	int playerHealth_;
	int beginTime_;
	int currentTime_;
};
#endif // !H_INFO