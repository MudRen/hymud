 inherit ROOM;
void create()
{
        set("short", "�����ջ"); 
        set("long", @LONG
���������������һ�ҿ�ջ�ˣ������������ջ����ȡ���Ǽ�������Ĳ�ͷ��
����Ҳûʲô���⣬�����ſ��С���ϴ���ϰ��ƺ�Ҳûʲô�������ű��ʱ�
����ķ�Ū�š�
LONG); 
        set("type","house");
        set("exits",([
                "east":__DIR__"xiaojie1",
                "up":__DIR__"kefang",
        ]) );
        
        set("objects",([
                __DIR__"npc/laoban" : 1,
        ]));
        set("coor/x",-590);
        set("coor/y",120);
        set("coor/z",0);
        setup();
        replace_program(ROOM);
}      
