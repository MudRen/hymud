 inherit ROOM;
void create()
{
        set("short", "���ſ�ջ����");
        set("long", @LONG
�����һƬ��ԫ�ϱڣ����䶫�������С���ݣ�û���ţ�û�д���ֻ��һ����
�Ŀ������紵�����ص��졣������һ������Ľ��죬��ȥ�Ƴ�����ϡ���Ա������
�ſ�ջ�������֣�����ԭ�ǹ�������Ъ��֮������֪Ϊʲô�������ˡ�
LONG
        );
        set("exits", ([ 
                "southwest" : __DIR__"qingtongxia",
                        ]));
        set("objects", ([
                __DIR__"npc/bandit" : 2,
        ]));
        set("outdoors", "eren"); 
        set("coor/x",0);
        set("coor/y",0);
        set("coor/z",0);
        setup();
} 
void init() {
        
         add_action("do_around", "around");
} 
int do_around(){
        object me, room;
        
        me=this_player();
        if (!me->query_temp("eren/bandit_around"))      return 0;
        tell_object(me,"���׷��������������ȥ��\n");
        room = find_object(__DIR__"banditcamp1");
        if(!objectp(room)) 
                room = load_object(__DIR__"banditcamp1");
        me->move(room); 
        message("vision",me->query("name")+"������׷ȥ�����˼�ȦҲ�����ˡ�\n",this_object());
        return 1;
} 
