 // An example book
inherit ITEM; 
void create()
{
        set_name("�糾��" , ({ "fengchen book", "book" }) );
        set_weight(600);
        set("unit", "��");
        set("long", "����һ�����������˷糾����֮��׿��������������Ż����Ѫд�͡� 
������������ޱȡ� \n");
        set("value", 100000);
        set("no_drop", 1);
        set("no_get", 1);
        set("no_sell", 1);
		set("skill", ([
                        "name":         "dodge",      //name of the skill
                        "exp_required": 100000 ,        //minimum combat experience required
			"jing_cost":    20+random(100),// jing cost every time study this
			"difficulty":	60,           // the base int to learn this skill
			"min_skill":	0,           // the minimum level you can learn
			"max_skill":	120            // the maximum level you can learn
		]) );
}
    
