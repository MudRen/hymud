 inherit ROOM;
void create()
{
        set("short", "�㳡��");
        set("long", @LONG
�����Ƿ��Ƴ������̾��������߻켯֮�����������Ǵ�ٹ��ˣ����Ƿ������䣬
ֻҪ����������Ǯ����������ͻ��ܵ�������к����κ��㲻֪�����£��������
��һ�£�������֪�����˾Ų���ʮ���������������˵ģ�����ģ�����ߵģ�����
�ģ���ҩ��...��Ӧ�о��С�
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "east" : __DIR__"ecloud2",
  "west" : __DIR__"fysquare",
  "south" : __DIR__"marry_room",
  "north" : __DIR__"stone1",
]));
        set("objects", ([
        __DIR__"npc/caifan" : 1,
                        ]) ); 
        set("outdoors", "fengyun");
        set("coor/x",10);
        set("coor/y",0);
        set("coor/z",0);
        setup();
        replace_program(ROOM);
}        
