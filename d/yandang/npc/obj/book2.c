// bojuan.c



inherit ITEM;
string* titles = ({
	"three-sword",
	"blood-sword",
	"doomsword",
	"fy-sword",
	"siqi-sword",
	"qingpingsword",
	"sharen-sword",
	"feixian-sword",
});

string* titles2 = ({
	"���Ž���",
	"Ѫ�½���",
	"���촵Ѫ����",
	"������ƽ�",
	"���潣��",
	"��ƽ����",
	"ɱ�˽���",
	"���ɽ���",
});

void create()
{
	int i;
	string wg,wg2;
	i=random(sizeof(titles));
	wg=titles[i];
	wg2=titles2[i];
	set_name("�书�ܼ�:"+wg2, ({ "kungfushu" , "book"}) );
	set_weight(50);
//	set("no_drop", "�������������뿪�㡣\n");
	if( clonep() )
		{
		set("unit", "��");
		set("long", "��������ʱ,����ǵ���"+wg2+"���书�ܼ�.\n");
		set("value", 0);
		set("no_pawn",1);
		set("material", "paper");
		set("skill", ([
			"name":		wg,
			"exp_required":	0,	// minimum combat experience required
			"jing_cost":	10,	// jing cost every time study this
			"difficulty":	10,	// the base int to learn this skill
			"max_skill":	210,	// the maximum level you can learn
			"min_skill":	0	// the maximum level you can learn
		]) );
	}
	else {
		set("unit", "��");
		set("long", "��������ʱ,����ǵ���"+wg2+"���书�ܼ�.\n");
		set("value", 0);
		set("no_pawn",1);
		set("material", "paper");
		set("skill", ([
			"name":		wg,
			"exp_required":	0,	// minimum combat experience required
			"jing_cost":	10,	// jing cost every time study this
			"difficulty":	10,	// the base int to learn this skill
			"max_skill":	210,	// the maximum level you can learn
			"min_skill":	0	// the maximum level you can learn
		]) );
	}
}

