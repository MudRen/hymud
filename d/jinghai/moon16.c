// Room: /d/jinghai/moon16.c

inherit ROOM;

void create()
{
	set("short", "ˮկ��ͷ");
	set("long", @LONG
�ƹ�ջ�����㷢�������и�����塣һ�Ÿߴ��ľ׮�����
�����ڰ��߿յ��ϣ��γ���Χǽ����Ȼ�����Ǹ�ˮկ��ͷ��һ��
���ɸߵ�Բľ������ǰ�յأ����������ţ�һ����죬���鼸��
����[����ˮկ]��������ͣ���ż��Ҵ�ľ��������ͷ�Ѻ���ˮ
���ֳֳ�ì���ص�Ѳ���š���ľ��ǰ����һ������[gaoshi]��
LONG
	);
        set("item_desc",([
        "gaoshi" : "
����ˮ·ͨ����

�����о��������ߣ����ɵǴ���
Υ�߸�ɱ���ۡ�

             ����ˮ�� ��\n",
]));

	set("exits", ([ /* sizeof() == 4 */
  "up2" : __DIR__"moon25",
  "up3" : __DIR__"moon26",
  "up1" : __DIR__"moon24",
  "south" : __DIR__"moon10",
  "east" : __DIR__"moon38",
]));
        set("outdoors","jinghai");
        set("objects",([
        __DIR__"npc/yong1" : 2,
]));


	setup();
	replace_program(ROOM);
}
