// guanmu2.
// by dicky

inherit ROOM;

void create()
{
        set("short","��ľ��");
        set("long", @LONG
���ֱ��ϵĹ�ľԽ��Խ�࣬·���ϵľ�����ʱ�İ�����ֽŻ��ƣ�һЩ��
���г���ٿ�Ĵڳ�һ�����ߣ������ľ�������
LONG
        );

	set("outdoors", "houjizhen");

        set("exits", ([
                "southeast" :__DIR__"songlin2",
                "northup" :__DIR__"shanlu5",
        ]));
        
        setup();
        replace_program(ROOM);

}


