// songlin2.c
// by dicky

inherit ROOM;

void create()
{
        set("short","ɽ������");
        set("long", @LONG
������ɽ�������У���Ƭ���ֻ�ɽ���ɣ�εε�дУ����ǹ���
����ȹ�ۣ�������װ��ø�����ȶ���! ������ï�ܵ������֣�ż��
�б����ŵ�ɽ�������ԱߵĲݴ���ɳ������Ҫȥץ����ȴ�ַ�����
�ݴԡ�
LONG
        );

	set("outdoors", "houjizhen");

        set("exits", ([
                "southwest" :__DIR__"songlin1",
                "eastdown" :__DIR__"shanlu1",
                "northwest" :__DIR__"guanmu",
        ]));
        
        setup();
        replace_program(ROOM);

}

