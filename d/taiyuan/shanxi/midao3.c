#include <ansi.h> 
inherit ROOM;
void create() 
{ 
    set("short", "�ܵ�"); 
    set("long", @long
�����ܵ�����˷�����·��Ҳ��֪����������·����ģ�����·�Ǽٵģ�
�ܵ�һ��ǽ�ϵ���һյ�͵ƣ�������������Ȼ����ס�����ɱ����
long 
    ); 
    set("exits", ([ 
    	"east" : __DIR__"midao", 
    	"south" : __DIR__"midao4",
    	"west" : __DIR__"midao11",
    	"north" : __DIR__"midao1",
        ])); 
           set("item_desc", ([
                "�͵�": "һյ��ͨ���͵ơ�\n",
                "��": "һյ��ͨ���͵ơ�\n" 
        ]) );
    set("indoors","shanxi"); 
set("coor/x",-470);
        set("coor/y",-260);
        set("coor/z",94);
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