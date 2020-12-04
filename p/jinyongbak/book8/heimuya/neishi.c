//ROOM neishi.c
inherit ROOM;
void create()
{
        set("short", "С������");
        set("long", @LONG
������С�����ҡ���ʰ�þ�ϸ�쳣����һ��ȥ���ͷ��ִ���
����һ��������޵��ˡ�����Ҳ�����̧ͷ���㷢������Ȼ�Ǹ�
���ˣ�����ִ��һö�廨�룡
LONG    );
        set("exits", ([
             "west" : "/d/heimuya/xiaoshe",
        ]));
        set("objects", ([
             __DIR__"npc/dongfang": 1,
             __DIR__"npc/renwoxing": 1,
             __DIR__"npc/xiang": 1,
        ]));
        setup();
	replace_program(ROOM);
}

void init()
{
	object who = this_player();
	if (who && interactive(who)) 
		call_out ("fighting", 1, who);  
}

void fighting(object who)
{
	object where = environment(who);
	object dongfang = present("dongfang bubai",where);
	object ren = present("ren woxing",where);
	object xiang = present("xiang wentian",where);
	if(dongfang && ren && xiang) 
	{
		dongfang->fight_ob(ren);
		xiang->fight_ob(dongfang);
		ren->fight_ob(dongfang);
		dongfang->fight_ob(xiang);
	}
}
