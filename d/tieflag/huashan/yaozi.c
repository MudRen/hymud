 inherit ROOM;
void create()
{
        set("short", "���ӷ���");
        set("long", @LONG
�˴��±�ֱ���������޵�·���У�����ϸ�ۣ��м���������������֮�ϣ�һ��
����������գ�����·�������ˣ�������������Խż�̽Ѱʯ�ѣ�������¡�����
��������ӥ��һ�㡢���ҷ�ת����ſ�ͨ�����������ɴ����ϱ�������ͤ��
LONG
        );
    set("exits", ([ 
                "northwest" : __DIR__"chaoyang",
        "south" : __DIR__"qipan",
        ]));
   
    set("outdoors", "huashanfy"); 
    set("coor/x",-566);
    set("coor/y",-96);
    set("coor/z",73);
        setup();
}  
int valid_leave(object who,string dir){
    int i;
    
    i = who->query_cor();
    if(dir=="south" && i < 15){
        message("vision",who->name() + "����ʯ���ϵ�·��ҡ��ҡͷ��\n" 
                        , this_object(), who);
        return notify_fail("��������ǰ��·�����ɵ���Щȴ����\n");
        }
    return 1;
}     
