 inherit ROOM;
void create()
{
        set("short", "��Ѩ");
        set("long", @LONG
�������еĹ������㿴��������ܵľ�ɫ��ֻ����ʯ��������·����
���ӣ����Ѿ���ʧ�˷��򡣼�ֻС��������ű�������ȥ����������
���ֲ��嶫������������������������˵��Ҳû���κ����塣����������
ֻ������������
LONG
        );
        set("exits", ([ 
                "east" : __DIR__"lighthole1",
                "west" : __DIR__"lighthole2",
                "north" : __DIR__"lighthole3",
                "south" : __DIR__"lighthole4",
                "out" : __DIR__"cliff",
        ]));
        set("coor/x",200);
        set("coor/y",-50);
        set("coor/z",30);
        setup();
}  
