#include <list>
#include "Perticipant.h"
#include "Barrier.h"

int main()
{
	Participant *mas_part[] = { new Human("Human", 2, 5), new Cat("Cat", 5, 8), new Robot("Robot", 2, 15) };  //������ ����������
	Barrier *mas_barr[] = { new RunningTrack("Running Track", 15), new Wall("Wall", 1) };  //������ ����������

	for (int i = 0; i < 3; i++)     //���������� �� ������� ���������
	{
		for (int k = 0; k < 2; k++)   //�������� �������� 2 �����������
		{
			while (mas_part[i]->Get_value() <= mas_barr[k]->Get_value())    //������� ������ ������� ��������� ����������� �����������
			{
				mas_part[i]->Set_value();
				if (k == 0)          //���� ������� �������
				{					
					if (mas_part[i]->Get_value() == mas_part[i]->Get_max_run())   //���� �������� ������ ��������� ����� ������������
					{						
						mas_part[i]->Set_barrier(1);
						break;                             //����������� �������
					}		
					mas_part[i]->Run();
				}
				else                 //���� �����
				{					
					if (mas_part[i]->Get_value() == mas_part[i]->Get_max_jump())   //���� �������� ������ ��������� ����� ������������
					{			
						mas_part[i]->Set_barrier(2);
						break;                             //����������� �������
					}
					mas_part[i]->Jump();
				}
			}
		}
	}

	cout << endl << "RESULTS" << endl << endl;
	for (int i = 0; i < 3; i++)     //���������� �� ������� ���������
	{
		if (mas_part[i]->Get_barrier() == 1)
		{
			if (mas_part[i]->Get_value() < mas_barr[0]->Get_value())
			{
				cout << "Participant " << mas_part[i]->Get_name() << " did not pass " << mas_barr[0]->Get_name() << ". Distance: " << mas_part[i]->Get_value() << endl;
			}
		}
		else if (mas_part[i]->Get_barrier() == 2)
		{
			if (mas_part[i]->Get_value() < mas_barr[1]->Get_value())
			{
				cout << "Participant " << mas_part[i]->Get_name() << " did not pass " << mas_barr[1]->Get_name() << ". Height: " << mas_part[i]->Get_value() << endl;
			}
		}
		else
		{
			cout << "Participant " << mas_part[i]->Get_name() << " passed all barriers." << endl;
		}
	}
}