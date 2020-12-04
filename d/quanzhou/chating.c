// Room: /d/quanzhou/chating.c
// Date: May 7, 96   Jay

inherit ROOM;

void create()
{
        set("short", "��ͤ");
        set("long", @LONG
����һ��·�ߵ�С��ͤ����ɽ·���˳��ڴ˴�ЪЪ�š�ͤ����
�м������Ӻͼ�֧���ʡ���Χ��һƬ���֡�
LONG );
        set("exits", ([
                "west" : "/d/quanzhou/qzroad4",
        ]));
        set("objects", ([
		"/d/jinyong/book8/quanzhou/npc/xiang" : 1,
		"/d/jinyong/book8/quanzhou/npc/riyuedizi" : 3,
		"/d/jinyong/book8/quanzhou/npc/taishandizi" : 3,
        ]));
        set("outdoors", "quanzhou");
//	set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}

void init()
{
	object who = this_player();
	if (who && interactive(who)) 
		call_out ("xiangsay", 1, who);  
}

void xiangsay(object who)
{
	object xiang = present("xiang wentian", environment(who));
	if(xiang)
	{
		message_vision("$N��$n˵���� ��λ"+ RANK_D->query_respect(who) +"һ����ЪЪ�ţ�ƷƷ��ɣ�\n",xiang,who);
	}
}