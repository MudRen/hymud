 inherit ROOM;
void create()
{
        set("short", "ɽ����"); 
        set("long", @LONG
�˴��������ߣ����ǵ�����ν����һʱ�ġ�����ɽׯ���ˣ����ԴӸ���ɽׯ��
������ׯ����������㿪ʼһ��Ϳ���ˣ�������˵ɽׯ����ס���˼����ŹŹֹ�
���ˣ��ܴ�·�Ĺ���·���Գ������ߴε����ߺ������紦�ӣ�����ȴ�������˰ٱ�
����̫ƽ��·����������ͷģ��������סȥ·��һ���п��ʾ��������飩��
����·�ڱ���ס�ˡ�
LONG);
        set("outdoors", "fugui");
        set("type","road");
        set("exits",([
                "west":__DIR__"shanlu1",
                "south":__DIR__"xiaojie1",
        "northup":__DIR__"shandao8",
        ]) );
        
        set("item_desc", ([
                "gaoshi": @TEXT
���ռ����򸽽����˲�Ᵽ������д������������޳���ҹ���ټң�
����ɽ·��ֹͨ�У�����ԸЭ���ٸ������߿ɽҴ˸�ʾ��Э�����á�
�����塡������飩
TEXT
        ]) );  
        set("objects", ([
                __DIR__"npc/jinshizi" : 1,
                __DIR__"npc/jiagun" : 1,
                __DIR__"npc/meirujia" : 1,
        ]) );
        set("gaoshi",1);
        set("coor/x",-580);
        set("coor/y",130);
        set("coor/z",0);
        setup();
        
} 
void init(){
        add_action("do_jie", "jie");
} 
int do_jie(string arg){
        object jin;
        if (arg == "gaoshi" && query("gaoshi")) {
                if(present("jin shizi", this_object())) {
                        jin = present("jin shizi", this_object());
                        jin->do_jie(arg);
                } else {
                        message_vision("���ظ�ʾ���˲��ڣ��Ȼ�������Ұɡ�\n", this_player());
                }
        } 
        return 1;
}  
int valid_leave(object me, string dir)
{
        object ob, yayi;    
            
        if (!yayi=present("jin shizi",this_object()))
        if (!yayi=present("jia gun",this_object()))
                return 1;
        
        if ( userp(me) && dir=="northup" ) {
                if (!ob=present("yao pai",me))
                        return notify_fail(yayi->name()+"��ס�����ȥ·��������ʾ�ɡ�\n");
                if (!me->query_temp("yaopai"))
                        return notify_fail(yayi->name()+"˵�������������Ǵ�����͵���ģ���\n");
                return 1;
        }
        
        return 1;
}    
