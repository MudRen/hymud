 // TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "������");
        set("long", @LONG
���·ת����ǰ��ɫ����һ�䣬һ����ˮ���춼����������壬Ȼ������¯��
�޺���������¾��۶��£�һ��һ̶�����پ�̶����˵�����ÿ�����֮����ˮ
����������������ۣ��۶����ۣ�����ǧ����ڣ�����������裬��̬���
LONG
        );
        set("exits", ([ 
  "southdown" : __DIR__"mroad1",
//  "up" : AREA_SHENSHUI"midao1",
  "northwest" : __DIR__"zhulin",
]));
    set("item_desc", ([
        "����": "������Ȼ�����ޱȣ���ʯ��ͻأ��ƽ����������Ŵ��⣨cliff������climb����ȥ��\n",
        "cliff": "������Ȼ�����ޱȣ���ʯ��ͻأ��ƽ����������Ŵ��⣨cliff������climb����ȥ��\n",
    ]) );
    set("outdoors", "huangshan");
    set("coor/x",-550);
    set("coor/y",-480);
        set("coor/z",20);
        setup();
}  
void init(){
        add_action("do_climb","climb");
}  
int do_climb(string arg){
        object me;
        me= this_player();
        if(!arg || arg != "cliff"){
                return 0;
        }       
        if (me->query_temp("jiulong_climb")) {
                tell_object(me,"���Ѿ����������ˡ�\n");
                return 1;
        }
        message_vision("$Nץס������ͻ����ʯ�飬����С����ȥ��\n", me);
   me->start_busy(2);
        call_out("arrive", 2, me);
        me->set_temp("jiulong_climb",1);
        return 1;
}   
int arrive(object me){
        int i;
        object room;
        if (me->is_ghost())     return 1;
        i = me->query_skill("dodge",1);
        if(i < 30){
                message_vision("$Nһʧ�֣����������������\n",me);
                me->receive_wound("qi",100);
        }else if (i < 50 && !random(5)){
                message_vision("$Nһʧ�֣����������������\n",me);
                me->receive_wound("qi",100);
        }else {
                room=find_object("/d/huangshan/pond");
                if(!objectp(room)) 
                        room = load_object("/d/huangshan/pond"); 
                me->move(room);
                me->delete_temp("jiulong_climb");
                message_vision("$N����������������\n",me);
        }       
        return 1;
}
