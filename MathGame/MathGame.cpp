//#include <iostream>;
//#include <thread>
//#include <chrono>
//using namespace std;
//
//enum enLevel{Easy = 1, Mid = 2, Hard = 3, Blend = 4};
//
//enum enOperation{Add = 1, Sub = 2, Mul = 3, Div = 4, Mix = 5};
//
//struct Question {
//	int Operand1;
//	int Operand2;
//	enOperation Operation;
//	int Answer;
//};
//
//struct FinalResult {
//	int NumberOfQuestions;
//	enLevel Level;
//	enOperation OPeration;
//	int NumberOfRightAnswers;
//	int NumberOfWrongAnswers;
//};
//
//int HowManyQuestions() {
//	int NumberOfQuestions;
//	cout << "How many questions you want to answer? ";
//	cin >> NumberOfQuestions;
//	return NumberOfQuestions;
//}
//
//enLevel QuestionLevel() {
//	int QuestionLevel;
//	cout << "Enter question level [1] Easy, [2] Mid, [3] Hard, [4] Mix? ";
//	cin >> QuestionLevel;
//	return (enLevel)QuestionLevel;
//}
//
//enOperation OperationType() {
//	int Operation;
//	cout << "Enter operation type [1] Add, [2] Sub, [3] Mul, [4] Div, [5] Mix? ";
//	cin >> Operation;
//	return (enOperation)Operation;
//}
//
//int RandomNumber(int From, int To) {
//	int Random;
//	Random = From + rand() % (To - From + 1);
//	return Random;
//}
//
//void PrintQuestion(Question Q) {
//	if (Q.Operation == Add) {
//		cout << Q.Operand1 << "\n";
//		cout << Q.Operand2 << " +\n";
//		cout << "------------------------------\n";
//	}
//	else if (Q.Operation == Sub) {
//		cout << Q.Operand1 << "\n";
//		cout << Q.Operand2 << " -\n";
//		cout << "------------------------------\n";
//	}
//	else if (Q.Operation == Mul) {
//		cout << Q.Operand1 << "\n";
//		cout << Q.Operand2 << " *\n";
//		cout << "------------------------------\n";
//	}
//    else {
//		cout << Q.Operand1 << "\n";
//		cout << Q.Operand2 << " /\n";
//		cout << "------------------------------\n";
//	}
//}
//
//int DoingOperation(Question Q) {
//	int Result = 0;
//
//	switch (Q.Operation) {
//	case Add:
//		Result = Q.Operand1 + Q.Operand2;
//		break;
//	case Sub:
//		Result = Q.Operand1 - Q.Operand2;
//		break;
//	case Mul:
//		Result = Q.Operand1 * Q.Operand2;
//		break;
//	case Div:
//		Result = Q.Operand1 / Q.Operand2;
//		break;
//	}
//	return Result;
//}
//
//bool CheckAnswer(Question Q, int Result) {
//	if (Q.Answer == Result)
//		return true;
//	else
//		return false;
//}
//
//void PrintAnswer(bool Answer, int Result) {
//	if (Answer)
//		cout << "Right answer.\n";
//	else {
//		cout << "Wrong answer.\n";
//		cout << "The right answer is : " << Result << "\n";
//
//	}
//}
//
//void ScreenColor(bool Answer) {
//	if (Answer)
//		system("color 2F");
//	else
//		system("color 4F");
//}
//
//void PassOrFail(int Right, int Wrong) {
//	if (Right > Wrong) {
//		cout << "\n\n";
//		cout << "\nCalculating final result";
//		for (int i = 0; i < 3; i++) {
//			cout << ".";
//			std::this_thread::sleep_for(std::chrono::milliseconds(1500));
//		}
//		ScreenColor(true);
//		cout << "\n-----------------------------------------------------\n";
//		cout << "Final result is pass :-)\n";
//		cout << "-----------------------------------------------------\n";
//	}
//	else {
//		cout << "\n\n";
//		cout << "\nCalculating final result";
//		for (int i = 0; i < 3; i++) {
//			cout << ".";
//			std::this_thread::sleep_for(std::chrono::milliseconds(1500));
//		}
//		ScreenColor(false);
//		cout << "\n-----------------------------------------------------\n";
//		cout << "Final result is fail :-(\n";
//		cout << "-----------------------------------------------------\n";
//	}
//}
//
//FinalResult PlayGame(enOperation OP, enLevel Level, int NumberOfQuestions) {
//	Question Q;
//	FinalResult FR;
//	int RightAnswers = 0;
//	int WrongAnswers = 0;
//	for (int i = 0; i < NumberOfQuestions; i++) {
//		cout << "\n\nQuestion [" << i + 1 << "/" << NumberOfQuestions << "]\n\n\n";
//		switch (Level) {
//		case enLevel::Easy:
//			Q.Operand1 = RandomNumber(0, 10);
//			Q.Operand2 = RandomNumber(0, 10);
//			break;
//		case enLevel::Mid:
//			Q.Operand1 = RandomNumber(11, 50);
//			Q.Operand2 = RandomNumber(11, 50);
//			break;
//		case enLevel::Hard:
//			Q.Operand1 = RandomNumber(51, 100);
//			Q.Operand2 = RandomNumber(51, 100);
//			break;
//		case enLevel::Blend:
//			Q.Operand1 = RandomNumber(0, 100);
//			Q.Operand2 = RandomNumber(0, 100);
//			break;
//		}
//
//		switch (OP)
//		{
//		case Add:
//			Q.Operation = Add;
//			break;
//		case Sub:
//			Q.Operation = Sub;
//			break;
//		case Mul:
//			Q.Operation = Mul;
//			break;
//		case Div:
//			Q.Operation = Div;
//			break;
//		case Mix:
//			Q.Operation = (enOperation)RandomNumber(1,4);
//			break;
//		}
//
//		PrintQuestion(Q);
//		cin >> Q.Answer;
//
//		int Result = DoingOperation(Q);
//
//		bool Check = CheckAnswer(Q, Result);
//		if (Check) {
//			PrintAnswer(Check, Result);
//			ScreenColor(Check);
//			++RightAnswers;
//		}
//		else {
//			PrintAnswer(Check, Result);
//			ScreenColor(Check);
//			++WrongAnswers;
//		}
//	}
//
//	PassOrFail(RightAnswers, WrongAnswers);
//
//	FR.NumberOfQuestions = NumberOfQuestions;
//	FR.Level = Level;
//	FR.OPeration = OP;
//	FR.NumberOfRightAnswers = RightAnswers;
//	FR.NumberOfWrongAnswers = WrongAnswers;
//	return FR;
//}
//
//string PrintLevel(enLevel Level) {
//	switch (Level) {
//	case Easy:
//		return "Easy";
//		break;
//	case Mid:
//		return "Mid";
//		break;
//	case Hard:
//		return "Hard";
//		break;
//	case Blend:
//		return "Mix";
//		break;
//	}
//}
//
//string PrintOperation(enOperation Operation) {
//	switch (Operation) {
//	case Add:
//		return "Add";
//	case Sub:
//		return "Sub";
//	case Mul:
//		return "Mul";
//	case Div:
//		return "Div";
//	case Mix:
//		return "Mix";
//	}
//}
//
//void PrintFinalResult(FinalResult FR) {
//	cout << "Number of questions : " << FR.NumberOfQuestions << "\n";
//	cout << "Question level : " << PrintLevel(FR.Level) << " \n";
//	cout << "Operation type : " << PrintOperation(FR.OPeration) << "\n";
//	cout << "Number of right answers : " << FR.NumberOfRightAnswers << "\n";
//	cout << "Number of wrong answers : " << FR.NumberOfWrongAnswers << "\n";
//	cout << "-----------------------------------------------------------------\n";
//}
//
//void ResetScreen() {
//	system("cls");
//	system("color 0F");
//}
//
//void StartGame() {
//	char Replay = 'Y';
//	FinalResult FR;
//	do {
//		ResetScreen();
//		FR = PlayGame(OperationType(), QuestionLevel(), HowManyQuestions());
//		PrintFinalResult(FR);
//		cout << "Do you want to play again? Y/N? ";
//		cin >> Replay;
//	} while (Replay == 'Y' || Replay == 'y');
//}
//
//int main() {
//	srand(time(0));
//	StartGame();
//	return 0;
//}

#include <iostream>
using namespace std;

enum enQuestionLevel { Easy = 1, Mid = 2, Hard = 3, MixLevel = 4 };

enum enOperationType { Add = 1, Sub = 2, Mul = 3, Div = 4, MixOp = 5};

struct stQuestion {
	int Number1 = 0;
	int Number2 = 0;
	enOperationType OpType;
	enQuestionLevel QuestionLevel;
	int CorrectAnswer = 0;
	int PlayerAnswer = 0;
	bool CheckAnswerResult = false;
};

struct stQuizz {
	stQuestion QuestionList[100];
	short NumberOfQuestions = 0;
	enQuestionLevel QuestionLevel;;
	enOperationType OpType;
	short NumberOfWrongAnswers = 0;
	short NumberOfRightAnswers = 0;
	bool IsPass = false;
};

short ReadHowManyQuestions() {
	int NumberOfQuestions = 0;
	do {
		cout << "How many questions do you want to answer? ";
		cin >> NumberOfQuestions;
	} while (NumberOfQuestions < 1 || NumberOfQuestions > 10);
	return NumberOfQuestions;
}

enQuestionLevel ReadQuestionLevel() {
	short QuestionLevel = 0;
	do {
		cout << "Enter question level [1] Easy, [2] Mid, [3] Hard, [4] Mix? ";
		cin >> QuestionLevel;
	} while (QuestionLevel < 1 || QuestionLevel > 4);
	return (enQuestionLevel)QuestionLevel;
}

enOperationType ReadOperationType() {
	short OperationType = 0;
	do {
		cout << "Enter operation type [1] Add, [2] Sub, [3] Mul, [4] Div, [5] Mix? ";
		cin >> OperationType;
	} while (OperationType < 1 || OperationType > 5);
	return (enOperationType)OperationType;
}

int RandomNumber(int From, int To) {
	int Random = From + rand() % (To - From + 1);
	return Random;
}

int SimpleCalculator(int Number1, int Number2, enOperationType OpType) {
	switch (OpType) {
	case enOperationType::Add:
		return Number1 + Number2;
	case enOperationType::Sub:
		return Number1 - Number2;
	case enOperationType::Mul:
		return Number1 * Number2;
	case enOperationType::Div:
		return Number1 / Number2;
	}
}

stQuestion GenerateQuestion(enQuestionLevel QuestionLevel, enOperationType OpType) {
	stQuestion Question;
	if (QuestionLevel == enQuestionLevel::MixLevel)
		QuestionLevel = (enQuestionLevel)RandomNumber(1, 3);
	if (OpType == enOperationType::MixOp)
		OpType = (enOperationType)RandomNumber(1, 4);
	Question.OpType = OpType;

	switch (QuestionLevel) {
	case enQuestionLevel::Easy:
		Question.Number1 = RandomNumber(1, 10);
		Question.Number2 = RandomNumber(1, 10);
		Question.CorrectAnswer = SimpleCalculator(Question.Number1, Question.Number2, Question.OpType);
		Question.QuestionLevel = QuestionLevel;
		return Question;
	case enQuestionLevel::Mid:
		Question.Number1 = RandomNumber(11, 50);
		Question.Number2 = RandomNumber(11, 50);
		Question.CorrectAnswer = SimpleCalculator(Question.Number1, Question.Number2, Question.OpType);
		Question.QuestionLevel = QuestionLevel;
		return Question;
	case enQuestionLevel::Hard:
		Question.Number1 = RandomNumber(51, 100);
		Question.Number2 = RandomNumber(51, 100);
		Question.CorrectAnswer = SimpleCalculator(Question.Number1, Question.Number2, Question.OpType);
		Question.QuestionLevel = QuestionLevel;
		return Question;
	}
}

void GenerateQuizzQuestions(stQuizz& Quizz) {
	for (int Question = 0; Question < Quizz.NumberOfQuestions; Question++) {
		Quizz.QuestionList[Question] = GenerateQuestion(Quizz.QuestionLevel, Quizz.OpType);
	}
}

char GetOpSymbol(enOperationType OpType) {
	switch (OpType) {
	case enOperationType::Add:
		return '+';
	case enOperationType::Sub:
		return '-';
	case enOperationType::Mul:
		return '*';
	case enOperationType::Div:
		return '/';
	}
}

void PrintTheQuestion(stQuizz Quizz, int NumberOfQuestion) {
	cout << "Question [" << NumberOfQuestion + 1 << "/" << Quizz.NumberOfQuestions << "]\n";
	cout << Quizz.QuestionList[NumberOfQuestion].Number1 << "\n";
	cout << Quizz.QuestionList[NumberOfQuestion].Number2 << " ";
	cout << GetOpSymbol(Quizz.QuestionList[NumberOfQuestion].OpType);
	cout << "\n";
	cout << "-------------------\n";
}

int ReadPlayerAnswer() {
	int PlayerAnswer = 0;
	cin >> PlayerAnswer;
	return PlayerAnswer;
}

void SetScreenColor(bool Answer) {
	if (Answer)
		system("color 2F");
	else
		system("color 4F");
}

void CorrectTheQuestionAnswer(stQuizz& Quizz, int NumberOfQuestion) {
	if (Quizz.QuestionList[NumberOfQuestion].CorrectAnswer != Quizz.QuestionList[NumberOfQuestion].PlayerAnswer) {
		Quizz.NumberOfWrongAnswers++;
		Quizz.QuestionList[NumberOfQuestion].CheckAnswerResult = false;
		cout << "Wrong answer :-(\n";
		cout << "The correct answer is : " << Quizz.QuestionList[NumberOfQuestion].CorrectAnswer <<"\n";
	}
	else {
		Quizz.NumberOfRightAnswers++;
		Quizz.QuestionList[NumberOfQuestion].CheckAnswerResult = true;
		cout << "Right answer :-)\n";
		cout << "\n";
	}
	cout << "\n";
	SetScreenColor(Quizz.QuestionList[NumberOfQuestion].CheckAnswerResult);
}

void AskAndCorrectQuestions(stQuizz& Quizz) {
	for (int Question = 0; Question < Quizz.NumberOfQuestions; Question++) {
		PrintTheQuestion(Quizz, Question);
		Quizz.QuestionList[Question].PlayerAnswer = ReadPlayerAnswer();
		CorrectTheQuestionAnswer(Quizz, Question);
	}
}

string GetFinalResult(bool Pass) {
	if (Pass) {
		return "Pass :-)";
	}
	else {
		return "Fail :-(";
	}
}

string PrintLevel(enQuestionLevel Level) {
	string Levels[4] = { "Easy", "Mid", "Hard", "Mix" };
	return Levels [Level - 1];
}

string PrintOperation(enOperationType Operation) {
	string Op[5] = { " + ", " - ", " * "," / " ," Mix "};
	return Op[Operation - 1];
}

bool IsPass(stQuizz Quizz) {
	if (Quizz.NumberOfRightAnswers > Quizz.NumberOfWrongAnswers) {
		Quizz.IsPass = true;
	}
	else {
		Quizz.IsPass == false;
	}
	return Quizz.IsPass;
}

void PrintQuizzResults(stQuizz& Quizz) {
	cout << "\n";
	cout << "-------------------------------------------------------\n\n";
	cout << "Final result is " << GetFinalResult(IsPass(Quizz));
	cout << "\n-------------------------------------------------------\n\n";

	cout << "Number of questions : "     << Quizz.NumberOfQuestions         << "\n";
	cout << "Question level : "          << PrintLevel(Quizz.QuestionLevel) << " \n";
	cout << "Operation type : "          << PrintOperation(Quizz.OpType)    << "\n";
	cout << "Number of right answers : " << Quizz.NumberOfRightAnswers      << "\n";
	cout << "Number of wrong answers : " << Quizz.NumberOfWrongAnswers      << "\n";
	cout << "-----------------------------------------------------------------\n";
}

void PlayGame() {
	stQuizz Quizz;

	Quizz.NumberOfQuestions = ReadHowManyQuestions();
	Quizz.QuestionLevel = ReadQuestionLevel();
	Quizz.OpType = ReadOperationType();

	GenerateQuizzQuestions(Quizz);
	AskAndCorrectQuestions(Quizz);
	PrintQuizzResults(Quizz);
}

void ResetScreen() {
	system("cls");
	system("color 0F");
}

void StartGame() {
	char PlayAgain = 'Y';
	do {
		ResetScreen();
		PlayGame();
		cout << "Do you want to play again? Y/N? ";
		cin >> PlayAgain;
	} while (PlayAgain == 'Y' || PlayAgain == 'y');
}

int main() {
	srand(time(0));
	StartGame();
	return 0;
}