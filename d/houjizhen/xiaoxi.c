// xiaoxi.c
// by dicky

inherit ROOM;

void create()
{
        set("short", "ɽ��СϪ");
        set("long", @LONG
��ɽ·���Ա߳�����һ��СϪ����Χ�������ˣ�ֻ��С����ˮ��������
�졣һЩ�ڿʵĶ�����Ϫ�ߺ�ˮ��Զ��������һЩ������ģ���Ķ���Ҳ��Ϫ
�����֡�������һ����ɽ��·����������ϡ��һƬ����ͨ�����
LONG
        );
        
	set("outdoors", "houjizhen");
	set("resource/water", 1);

        set("exits", ([           
		"northup" : __DIR__"zhulin1",
                "southup" : __DIR__"shanlu4",
		"westup" : __DIR__"xiaoxi1",
        ]));


        setup();
	replace_program(ROOM);
}
