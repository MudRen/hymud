 inherit ROOM;
void create()
{
        set("short", "��ʮһ�ɵļ�"); 
        set("long", @LONG
���Сľ����ɽ���������Ǵ����ʮһ�ɵļ��ˡ�����һ��ľ���⣬�����Ｘ
��ʲô��û�У��Ե�˵���������壬˵�����Ŀ��飬ÿ����ʮһ�ɻص�����������
ʼʱҲ�����ú������������˺����������ķ��������ˡ�û���˵ĵط�����Ҳ
�ǹ¶��ĵط���                                
LONG); 
        set("type","street");
        set("exits",([
        "out":__DIR__"mudedge",
        ]) );
       set("outdoors", "wolfmount");
        set("objects", ([
        __DIR__"npc/xiao" : 1,
                        ]) );
        set("coor/x",-570);
        set("coor/y",-700);
        set("coor/z",0); 
        setup();
        replace_program(ROOM);
} 
