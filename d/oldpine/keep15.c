 // Room: /d/oldpine/keep1.c
inherit ROOM; 
void create()
{
        set("short", "����կ��Χ");
        set("long", @LONG
����̩ɽ�м���֮��������ɽ�����ƣ���ϼ��������ʯ�����֣���
�͵��֣�ʵ���������ѹ�֮��,ǧ���������������ֺú�ռɽΪ��������
�����ж��ҸͶ��𣬵�����Ҫ�ɼ�һ�ߣ������Կɼ�����ɽկģ����
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"keep1",
  "east" : __DIR__"keep2",
]));
        set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/bandit_guard" : 4,
]));
        set("no_clean_up", 0); 
        set("coor/x",580);
        set("coor/y",2350);
        set("coor/z",90);
        setup();
        replace_program(ROOM);
}     
