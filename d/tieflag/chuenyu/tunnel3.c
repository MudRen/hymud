 inherit ROOM;
void create()
{
        set("short", "����");
        set("long", @LONG
����ںڰ������������ֲ�����ָ��Ψһ�Ĺ�������ǽ�Ϻ���������
���͵ơ����Ϻ�ǽ�ϲ����˰���ɫ��Ѫ�ۣ�ɢ�����������������ϴ�����
�������������ĵ�����ص�������ë����Ȼ��
LONG
        );
        set("exits", ([ /* sizeof() == 3 */
  "east" : __DIR__"dungeon",
//  "north" : __DIR__"tunnel5",
  "south"   : __DIR__"tunnel2",
])); 
        set("coor/x",120);
        set("coor/y",150);
        set("coor/z",20);
        setup();
}    
