// Room: some place in ��ţ����
// uphill2.c

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
"northup" : __DIR__"uphill3",
"south": __DIR__"uphill1",

]));
        set("objects", ([ /* sizeof() == 2 */
                __DIR__"npc/yao" : 2]));
        set("no_clean_up", 0);
	set("outdoors", "xy28");
        setup();
}

