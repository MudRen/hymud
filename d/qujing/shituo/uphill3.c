// Room: some place in ��ţ����
// uphill3.c

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
"northeast" : __DIR__"uphill4",
"southdown": __DIR__"uphill2",
]));
        set("objects", ([ /* sizeof() == 2 */
                __DIR__"npc/yao" : random(5)]));
        set("no_clean_up", 0);
	set("outdoors", "xy28");
        setup();
}

