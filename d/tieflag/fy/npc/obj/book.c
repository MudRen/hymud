 // book.c
inherit ITEM; 
void create()
{
        string *names = ({
                "���ε���ѡ��", "����躡�", "��̫���硹", "�������ļ���",
                "��˵�ɡ�", "������־��", "�����项", "��٫��իʫ����",
                "����ʿ�д���", "��ˮ��ͼע��"
        }); 
        set_name( names[random(sizeof(names))], ({ "book" }));
        set_weight(600);
        set("unit", "��");
        set("long", "����ʱ�¶����˳������鼮��\n");
        set("value", 100);
		set("skill", ([
			"name":	      "literate",	// name of the skill
			"exp_required":	0,	// minimum combat experience required
			"jing_cost":	30,	// jing cost every time study this
			"difficulty":	20,	// the base int to learn this skill
			"max_skill":	59
	
		]) );
        setup();
}   
