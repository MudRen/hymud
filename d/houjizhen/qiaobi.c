// qiaobi.c
// by dicky

inherit ROOM;

void create()
{
        set("short","�ͱ�");
        set("long", @LONG
������ͣͣ�������Լ�����һ���ͱڣ�̧ͷ��Լ�ɼ�ɽ���Ƶ�ɽ�£�
ɽ����棬���������������Ŀ�������·���ϵ���ʯ��͹��ƽ��һ��С��
�Ϳ���Ҫˤ����Ԩ��һ���˵�������Ͳ�������ǰ�ˡ�
LONG                           
        );

        set("outdoors", "houjizhen");

        set("exits", ([
              "eastdown" : __DIR__"shanlu5",
              "westup" : __DIR__"shanya",
        ]));

	setup();
	replace_program(ROOM);
}

