 // Room: woshi.c --- by MapMaker
inherit ROOM; 
void create()
{
    set("short", "���С��"); 
        set("long", @LONG
���ֻ��һ����������������ҵĻ�,�Ǿ���"��"�ˡ����г����Ŵ���,����
����.�б�������ʰ���쳣�����ྲ.��˿����͸������,�Եø��ⰲ��.
LONG); 
        //{{ --- by MapMaker
        set("type","indoors");
        set("exits",([
        "east":__DIR__"dating",
        ]) );
        //}}
        set("objects", ([
                __DIR__"npc/manager" : 1,
        ]) );
        set("indoors", "taishan");
        set("coor/x",300);
        set("coor/y",2440);
        set("coor/z",150); 
        setup();
        replace_program(ROOM);
}   
