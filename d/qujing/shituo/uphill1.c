// Room: some place in ��ţ����
// uphill1.c

inherit ROOM;

void create()
{
  set ("short", "ʨ����");
  set ("long", @LONG
��ɽ�����˰���ʨ���룬�м�����ʨ�ն�������������ħͷ��
ʨ�����Ǵ����������Ϣ֮�أ��������޲���������������
�Դ�ȴ֪֮���١������������������������ǧС����ר����
����ˡ�
LONG);
set("exits", ([ /* sizeof() == 4 */
"north" : __DIR__"uphill2",
"southdown": __DIR__"hill",
]));
        set("objects", ([ /* sizeof() == 2 */
                __DIR__"npc/yao" : 3]));
        set("no_clean_up", 0);
        set("outdoors", "xy28");
        setup();
        replace_program(ROOM);
}


