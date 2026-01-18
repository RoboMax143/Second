#pragma once


class Counter {
public:

	Counter();
	Counter(int startValue);
	~Counter();

	void count_plus();

	void count_minus();

	int get_count() const;   //?

	void reset_count();

	void set_count(int value);

	void multiply_count(int mult);

	bool is_empty() const;

private:
	int value_;
};