// Room: /d/linzhi/lin07.c

inherit ROOM;

void create()
{
	set("short", "�һ�������");
	set("long", @LONG
���ߵ��һ������ڣ�����ȥ�ͽ����һ��������ﳤ������
Ȼ��Ұ��������ÿ�����ʱ���ܶ��˶��������ժ���ӡ���˵ζ
���ر�ĺá�·��һ��ʯ���Ϻ������һЩ�֡�
LONG
	);
	set("item_desc",([
          "ʯ��":"
                  southup      ����
                  east         ͨ��
                  west         ��һ�� \n", ]));
	set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"lin06/exit",
  "west" : __DIR__"lin08",
  "southup" : __DIR__"lin11",
]));
        set("outdoors", "linzhi");
        set("cannot_build_home", 1);
        set("altitude", 2600);
	setup();
	replace_program(ROOM);
}
