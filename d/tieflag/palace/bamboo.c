 inherit ROOM;
void create()
{
        set("short", "������");
        set("long", @LONG
����һƬ���̵����֡���������Լ�ɼ�һЩ̨ͤ¥�󣬴�������ӳ����ǽ
���ߣ������Ծ����Ѽ��ĸо���һ��СϪ�����л�����������Ƭ���Ǵ��̵���
Ҷ�����Ʈ�衣�м�Ƭ���������Ϫ���ϣ�������֪�Ӻδ����µķۺ�ɫ�Ļ�
�꣬����������СϪƯ�����¡�
LONG
        );
        set("exits", ([ 
  "east" : __DIR__"jinghouse",
  "south" : __DIR__"bamboo2",
  "west" : __DIR__"house",
]));
        set("outdoors", "palace");
        set("resource/water",1);
        set("coor/x",290);
        set("coor/y",-50);
        set("coor/z",10);
        setup();
        replace_program(ROOM);
}       
