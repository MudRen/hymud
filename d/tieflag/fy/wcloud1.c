 inherit ROOM;
void create()
{
        set("short", "�㳡��");
        set("long", @LONG
���ƹ㳡�ڶ������ַ������������Ƿ��Ƴ��з�ɧ���˴Ծ�֮�ء���˵���º�
��������С��̽�������������е���š��ϱߵĿ���ÿ�궼����һ��ѡ�ο��ԣ�ǰ
�������뾩�����ԡ���������̽��ʫ̨���Ƿ�ɧ�������������ǵ���֮���ĵط���
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"poemp",
  "south" : __DIR__"examp",
  "west"  : __DIR__"wcloud2",
  "east"  : __DIR__"fysquare",
]));
        set("objects", ([
        __DIR__"npc/song": 1,
        __DIR__"npc/xiwei": 4,
                        ]) );  
        set("outdoors", "fengyun");
        set("coor/x",-10);
        set("coor/y",0);
        set("coor/z",0);
        setup();
} 
int valid_leave(object me, string dir)
{
        object ob,room;
        int i;
        mapping condition;
        string *type;
        if( userp(me) && dir == "north")
        {
                
        condition = me->query_all_condition();
        if( mapp(condition) ) {
                type=keys(condition);
                for (i=0;i<sizeof(type);i++) {
                        if (type[i]!="drunk" && type[i]!="buffed")
                           return notify_fail("̽��ʫ̨������ķس���\n");
                } 
        }        
        if(me->query("eff_sen")<me->query("max_sen")*95/100
                ||me->query("eff_kee")<me->query("max_kee")*95/100
                ||me->query("eff_gin")<me->query("max_gin")*95/100 )
                return notify_fail("̽��ʫ̨������ķس���\n");
                
        if(objectp(ob = present("qinwei",this_object())) && random (3))
                return notify_fail(ob->name()+"����ȵ������ʹ�������֮���������˵Ȳ������ڣ�\n");       
        }       
        return 1;
} 
