// shanlu5.c
// by dicky

inherit ROOM;

void create()
{
        set("short","ɽ·");
        set("long", @LONG
������һ��ƫƧ��ɽ·�ϣ����ܹ�ľ�Դԣ�����滨��ݣ��˼�
������·��������Ѱ��ֻ�в�ҩ���˲Ÿҽ�����ɽ���㵽���Ҵ�Ѱ��
��·���͵�һʹ�����������������!
LONG                           
        );

	set("outdoors", "houjizhen");

        set("exits", ([
		"westup" : __DIR__"qiaobi",
		"southdown" : __DIR__"guanmu",
		"eastdown" : __DIR__"shanlu4",
		"north" : __DIR__"chating",
        ]));

        setup();
        replace_program(ROOM);

}

