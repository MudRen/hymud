//ROOM: xiaoshe.c

inherit ROOM;

void create()
{
	set("short", "С��");
        set("long", @LONG
����һ���ô����ɵ�С�ᡣһ���ţ����ŵ�һ��Ũ�ҵĻ�
�㣬���й���һ����Ůͼ�����������廨���棬������һ���ţ�
��������һ��ĵ���Ľ����������ѵ�����˭�ҹ���Ĺ뷿��
LONG    );
        set("exits", ([
            "east" : __DIR__"neishi",
            "out" :__DIR__"xiaohuayuan",
            "enter" :"/d/jinyong/book8/heimuya/neishi",
        ]));
        set("no_clean_up", 0);
        setup();
        //replace_program(ROOM);
}

int valid_leave(object me, string dir)
{
  	if(((int)me->query("jinyong/book8")!=8)&&(dir == "enter"))
	{
		return notify_fail("������ֹ��У���ǹ���ۣ���Ҫ��ȥ�����ˡ�\n");
	}
//return notify_fail((int)me->query("jinyong/book8"));
	return ::valid_leave();
}

