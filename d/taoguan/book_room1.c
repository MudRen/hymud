 inherit ROOM;
void create()
{
        set("short", "��¥");
        set("long", @LONG
���������Ĺ����ղ��鼮�ĵط�, ���ܵ�����϶����������顣
��Щ���Ѿ��ɵ�ֽ�Ŷ�������, ��һ�����ܾͻ�ɢ��������ɷɻҡ�
������ϸ�Ŀ��˿�, �������ﶼֻ��ЩѰ�����޵����鼮, �ƺ�û��
ʲ���ر�ġ���������һ��СС��ľ��ͨ����¥��
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
  "up" : __DIR__"book_room2",
  "south" : __DIR__"stoneroad2",
]));
        set("no_clean_up", 0); 
        set("coor/x",-40);
        set("coor/y",2140);
        set("coor/z",80);
        setup();
} 
