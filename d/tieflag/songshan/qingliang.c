 // TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "��������Ժ");
        set("long", @LONG
�ѽӽ�ɽ�ţ�����һ�磬��ǧ���ز������ܵİ�����Χ�ڵ�
�У�����������֮�У����������ޱȣ��ʴ�����������ÿ��������
��ӯ���������˱ǡ��˼����ɲ���Ϊ�����ˣ������˲�Զǧ����Ʒ
�����г��ϵ��Ƶ��ɲ衣ÿ�괺�����������������أ�����Ҫ��
������ɨ��������������ࡣ
LONG
        );
        set("exits", ([ 
  "northup" : __DIR__"lianhua",
  "east" : __DIR__"qingliang2",
]));
        set("coor/x",-220);
        set("coor/y",380);
        set("coor/z",50);
        set("objects", ([
                __DIR__"npc/lama2" : 1,
        ]) );
        setup();
        //replace_program(ROOM);
}      
int valid_leave(object me, string dir)
{
	if ( objectp(present("jin bo", environment(me))) && 
		dir == "east")
		return notify_fail("��ʤ����ס�����ȥ· ��׼��������ɣ����Ĵ��¡�\n");


	return ::valid_leave(me, dir);
}