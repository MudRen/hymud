 inherit __DIR__"no_killing_place";
void create()
{
    
        set("short", "С��");
    
        set("long", @LONG
�������ɵ�С��ͨ���ס�ˮ�����Ĵ�������������ˮ�峺���ף�վ����
�����������ؿ�������ʯ�̳ɵĺӴ�����ʱ�ι�������ڶ���ʯ��Ͷ���˵�����
��Ӱ���������಻�ϵ�ɽ�ͻ�����һ����ɫ����أ��������ɽ���������ż�����
�µ�СլԺ�����ܻ��ݷ��衣
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
                "west" : __DIR__"riverbank",    
                "east" : __DIR__"riverbanke",
        ]));
    
        set("no_magic", 1);
        set("outdoors","taoyuan");
    set("coor/x",250);
        set("coor/y",-40);
        set("coor/z",0);
    
        setup();
    
        
}   
int valid_leave(object who,string dir)
{
        if(dir=="east"){
                message("vision",who->name() + "������ȥ��ֻ������һ����" 
                                + who->name() + "���ű��ӣ�һƨ�������˵��ϡ�\n", this_object(), who);
                return notify_fail("��������һ������ײ��һ�����ε�ǽ�ϣ������˻����������˵��ϡ�\n");
                }
        return ::valid_leave(who, dir);
}
