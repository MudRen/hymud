 inherit ROOM;
void create()
{
        set("short", "������"); 
        set("long", @LONG
�����Ƕ�������һյ����ֽ�����������бб������Ͳ��ڶ�ǽ�������
ͣ��ҡ�Ρ��谵�ĵƹ����������ˣ�һ��˥�����͵Ĳз��ˣ�������ª����������
���̡�һ��������´󺺣���һ�����Ǹ��ܸߴ�ĺ����ˡ� 
LONG); 
        set("type","street");
        set("exits",([
                "down":__DIR__"broketower5",
        ]) ); 
        set("objects", ([
                __DIR__"npc/baili_changqing": 1,
                __DIR__"npc/deng":1,
                __DIR__"npc/hu_5":1
        ]));
        set("indoors", "bawang");
        setup(); 
    set("coor/x",200);
    set("coor/y",-210);
    set("coor/z",60);
        replace_program(ROOM);
}    
