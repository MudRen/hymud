// Room: /d/snow/innerhall.c
inherit ROOM;
void create()
{
        set("short", "�����Ժ");
        set("long", @LONG
�����Ǵ�����ݵ���Ժ��ƽ����ݵ���û�й����������ǲ���
���������ģ����������ҵ����ã������ͼҾ���Է��ֱ�λ�����
һ���ߵ������ԣ������Լ��񷿡����۵��Է��������ϵ��ߵ����ԣ�
���������쾮��
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"inneryard",
  "north" : __DIR__"mingren",
//  "east" : "/d/zwei/secret1",
]));
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}
