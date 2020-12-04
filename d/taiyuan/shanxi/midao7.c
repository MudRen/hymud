#include <ansi.h> 
inherit ROOM;
string light();
void create() 
{ 
    set("short", "�ܵ�"); 
    set("long", @long
�����ܵ�����˷�����·��Ҳ��֪����������·����ģ�����·�Ǽٵģ�
�ܵ�һ��ǽ�ϵ���һյ�͵ƣ�������������Ȼ����ס�����ɱ����
long 
    ); 
    set("exits", ([ 
    	"east" : __DIR__"midao1", 
    	"south" : __DIR__"midao",
    	"west" : __DIR__"midao2",
    	"north" : __DIR__"midao6",
        ])); 
    set("item_desc", ([
                "�͵�": (: light :),
                "��": (: light :),
        ]) );
    set("indoors","shanxi"); 
    set("coor/x",0); 
        set("coor/y",0); 
        set("coor/z",0); 
        setup(); 
} 
int valid_leave(object obj, string dir){
        int skills,i,damage;
        string  *dirc = ({ "��", "��", "��", "��" });
        skills=obj->query_skill("dodge",1);
        
        if(dir == "west" || dir == "south" || dir == "east" || dir == "north"){
        	if (random(10)>=5) {
            		message_vision(HIR"$N����������ǰ�У�ͻȻ����ಡ��������м���������"+dirc[random(4)]+"��ǽ�ڷ����������\n"NOR, obj); 
            		if( random(skills) < 50 ){
            			message_vision(HIR"�������۶�����$N���������������˸����ţ���\n"NOR,obj);
            			i = (int)obj->query("eff_qi");
        			damage = i/20;
        			obj->set("eff_qi",(int) i - damage );
        			i =  (int)obj->query("qi");
        			obj->set("qi",(int) i - damage);
        			return 1;
            		}
  			else{
  				message_vision(WHT"$N���������һ���粽����˷�������İ�����\n"NOR,obj);
  				return 1;
  			}
                }
        }       
        return 1;
}

string light(){
        object me;
        me = this_player();
        tell_object(me, "һյ��ͨ���͵ƣ����ǿ���ȥ���ŵ�λ�úͱ𴦲�һ����\n");
        tell_object(me, "��Ҳ�������ת(turn)һ�¡�\n");
        add_action("do_turn", "turn");
        return "";
}

int do_turn(string arg)
{
        object room;
        object me;
        if(!arg || arg=="")
        {
                write("��Ҫ��תʲô��\n");
                return 1;
        }
        if( arg == "�͵�" || arg == "��" || arg == "light")
        {
        	me = this_player();
        	message_vision("$N����������͵ƺͱ𴦵��͵Ʋ�һ����������ת��һ�¡�\n", me);
        	message_vision("ͻȻ��������һ��������¶���˰�����$N����������ž��һ�����˽�ȥ......\n",me);
        	room = find_object(__DIR__"midao8");
        	if(!objectp(room)) room = load_object(__DIR__"midao8");
        	message("vision",me->name()+"���������������\n",room);
        	me->move(room);
       	return 1;
        }
}