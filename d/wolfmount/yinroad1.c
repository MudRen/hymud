inherit ROOM;
void create ()
{
        set ("short", "����С·");
        set ("long", @LONG
����һ��������ʪ��С·��λ�ڳ����֮���ϣ���Χɢ����һЩ��ԫ�ϱڣ�·
���Ӳݴ��������ڹٸ����ٹ���������ΰ�����ʮ�ֺá������ǳ��ƵĻ�ɫ����
��һ˿������·������һ����ľ���ӣ�������飩���ϱ��ʲݵ�д��Щ�ٸ���ʾ��
LONG);
        set("exits", ([ //sizeof() == 4
                "east" : "/d/chenxiang/mw",
                "west" : __DIR__"yinroad2",
        ]));
        set("outdoors", "wolfmount");
        set("item_desc", ([
                "paizi": @TEXT
������ɽȺ�Ǻ��У�ռɽΪ����ר�Ŵ�ٹ������̣��ٸ������˼���
���ڴ��֮��ȫ�����������أ��ٸ�������ʱ��Ҫ���С����в���Ȱ
�棬˽�������վ���һ�к���Ը���
TEXT
        ]) );
        set("type", "road");
        set("coor/x",-600);
      set("coor/y",-540);
        set("coor/z",0);
        setup();
        replace_program(ROOM);
}  
