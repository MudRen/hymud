// look.c
// colored by ReyGod in 1/10/1997 ----- I love colorful world :)

#define C_MAP_S "/inherit/maps.c"
#include <room.h>
#include <ansi.h>
#include <combat.h>
#define TIME_TICK1 ((time()-900000000)*60)

inherit F_CLEAN_UP;

int look_room(object me, object env);
int look_item(object me, object obj);
int look_living(object me, object obj);
int look_room_item(object me, string arg);
string getper(object me, object obj);
string tough_level(int power);
string gettof(object me, object obj);
string getdam(object me, object obj);
string *tough_level_desc = ({
BLU"����һ��"NOR,BLU"��������"NOR,BLU"��֪����"NOR,BLU"��ѧէ��"NOR,BLU"����ǿǿ"NOR,
BLU"�����ž�"NOR,BLU"����é®"NOR,BLU"��֪һ��"NOR,BLU"����ͨͨ"NOR,BLU"ƽƽ����"NOR,

HIB"ƽ������"NOR,HIB"��ͨƤë"NOR,HIB"��������"NOR,HIB"������"NOR,HIB"����С��"NOR,
HIB"����С��"NOR,HIB"����Ѿ�"NOR,HIB"��������"NOR,HIB"��������"NOR,HIB"�ڻ��ͨ"NOR, 

CYN"�������"NOR,CYN"¯����"NOR,CYN"��Ȼ���"NOR,CYN"���д��"NOR,CYN"���д��"NOR,
CYN"��Ȼ��ͨ"NOR,CYN"�������"NOR,CYN"�޿�ƥ��"NOR,CYN"����Ⱥ��"NOR,CYN"����似"NOR,

HIC"�����뻯"NOR,HIC"��ͬ����"NOR,HIC"����Ⱥ��"NOR,HIC"�Ƿ��켫"NOR,HIC"�����ױ�"NOR,
HIC"��������"NOR,HIC"һ����ʦ"NOR,HIC"�������"NOR,HIC"�񹦸���"NOR,HIC"������˫"NOR,

HIR"��������"NOR,HIR"���춯��"NOR,HIR"������"NOR,HIR"������ʥ"NOR,HIR"�������"NOR,
HIR"��ǰ����"NOR,HIR"���˺�һ"NOR,HIR"��ز�¶"NOR,HIR"��ɨ����"NOR,HIR"��ɲ�"NOR,

HIY"�����ɵ�"NOR,HIY"��������"NOR,HIR"ǿ������"NOR,HIY"��������"NOR,HIR"ǰ�޹���"NOR,
HIY"��豹���"NOR,HIY"��������"NOR,HIY"���ž���"NOR,HIY"�����޵�"NOR,HIY"���µ�һ"NOR,
});
string *heavy_level_desc= ({
	"����",
	"����",
	"����",
	"����",
	"����",
	"����"	
});
void create() { seteuid(getuid()); }

int main(object me, string arg)
{
        object obj;
        int result;
	string str;
        if( !arg ) result = look_room(me, environment(me));
	else if(arg=="long") {
 	result = look_room(me, environment(me));
/*
        str = sprintf( "$miao#    %s%s",
              replace_string( environment(me)->query("long"), "\n", "\n$miao#")+"\n",
		environment(me)->query("outdoors")?"$miao#"+ NATURE_D->outdoor_room_description() : "" );
	write(str);
	return 1;
*/
		}
        else if( (obj = present(arg, me)) || (obj = present(arg, environment(me))))
             {
                if( obj->is_character() ) result = look_living(me, obj);
                else result = look_item(me, obj);
             } else result = look_room_item(me, arg);

        return result;
}

void realtime_map(object me,object env)
{
        object room_obj;
        mapping exits;
    int i;
        string map_room, map_room2,jiantou;
     string *dirs;
        mapping alldirs=([      
                        "northwest" : "          ",
                        "north"     : "          ",
                        "northup"   : "          ",
                        "northeast" : "          ",
                        "west"      : "          ",
                        "east"      : "          ",
                        "southeast" : "          ",
                        "south"     : "          ",
                        "southwest" : "          ",
                        "southdown" : "          ",
                        "eastup" : "          ",
                        "southup" : "          ",
                        "northdown" : "          ",
                        "eastdown" : "          ",
                        "westup" : "          ",
                        "westdown" : "          ",
                        "enter" : "          ",
                        "out" : "          ",
                        "up" : "          ",
                        "down" : "          ",
                        "left" : "          ",
                        "right" : "          ",
                        ]);  
       if( mapp(exits = env->query("exits")) ) 
        {                       
                dirs=keys(exits);
                for(i=0;i< sizeof(dirs);i++)
                {
                        if(!room_obj=find_object(exits[dirs[i]]))
                                room_obj=load_object(exits[dirs[i]]);
                        if(room_obj){
                                
                                if (room_obj->query("short"))
                                alldirs[dirs[i]]=room_obj->query("short");                              ;
                                }
        
                }
        
                jiantou="  ";
                map_room2=alldirs["enter"];
                if(alldirs["enter"]!="          "){
                        map_room2=alldirs["enter"];
                        jiantou=HIR+"��"+NOR;
                        }
                if(alldirs["up"]!="          "){
                        map_room2=alldirs["up"];
                        jiantou=HIC+"��"+NOR;
                        }
                if(alldirs["northdown"]!="          "){
                        map_room2=alldirs["northdown"];
                        jiantou="��";
                        }
                if(alldirs["northup"]!="          "){
                        map_room2=alldirs["northup"];
                        jiantou="��";
                        }
                if(alldirs["north"]!="          "){
                        map_room2=alldirs["north"];
                        jiantou="��";
                        }
                map_room=map_room2;
                for(i=0;i<(10-strlen(map_room2))/2;i++)
                        {
                                map_room =map_room+" ";
                                map_room =" "+map_room;
                        }
                printf("             %10s  %-10s  %-10s\n",
                alldirs["northwest"],map_room,alldirs["northeast"]);
                
                printf("                        %s   %s   %s\n",
                alldirs["northwest"]=="          " ? "  ":"��",
                jiantou,
                alldirs["northeast"]=="          " ? "  ":"��");
                
                jiantou="  ";
                map_room2=alldirs["westdown"];
                if(map_room2!="          ")
                                jiantou="��";
                if(alldirs["left"]!="          "){
                        map_room2=alldirs["left"];
                        jiantou="��";
                        }
                if(alldirs["westup"]!="          "){
                        map_room2=alldirs["westup"];
                        jiantou="��";
                        }
                if(alldirs["west"]!="          "){
                        map_room2=alldirs["west"];
                        jiantou="--";
                        }
                printf("             %10s%s",map_room2,jiantou);        
                map_room2=env->query("short") ? env->query("short"): "----------";
                map_room=HIG+map_room2+NOR;
                for(i=0;i<(10-strlen(map_room2))/2;i++)
                        {
                                if(alldirs["east"]=="          ")
                                map_room =map_room + " ";
                                else map_room=map_room + "-";
                                if(alldirs["west"]=="          ")
                                map_room =" "+ map_room;
                                else map_room ="-"+map_room;
                        }
                printf("%s",map_room);
                
                jiantou="  ";
                map_room2=alldirs["eastup"];
                if(map_room2!="          ")
                                jiantou="��";
                if(alldirs["right"]!="          "){
                        map_room2=alldirs["right"];
                        jiantou="��";
                        }
                if(alldirs["eastdown"]!="          "){
                        map_room2=alldirs["eastdown"];
                        jiantou="��";
                        }
                if(alldirs["east"]!="          "){
                        map_room2=alldirs["east"];
                        jiantou="--";
                        }
                
                printf("%s%-10s\n",jiantou,map_room2);
                
                jiantou="  ";
                map_room2=alldirs["out"];
                if(alldirs["out"]!="          "){
                        map_room2=alldirs["out"];
                        jiantou=HIR+"��"+NOR;
                        }
                if(alldirs["down"]!="          "){
                        map_room2=alldirs["down"];
                        jiantou=HIC+"��"+NOR;
                        }
                
                if(alldirs["southdown"]!="          "){
                                map_room2=alldirs["southdown"];
                                jiantou="��";
                                }
                if(alldirs["southup"]!="          "){
                        map_room2=alldirs["southup"];
                        jiantou="��";
                        }
                if(alldirs["south"]!="          "){
                        map_room2=alldirs["south"];
                        jiantou="��";
                        }
                map_room=map_room2;
                for(i=0;i<(10-strlen(map_room2))/2;i++)
                        {
                                map_room =map_room + " ";
                                map_room =" "+map_room;
                        }
                printf("                        %s   %s   %s\n",
                alldirs["southwest"]=="          " ? "  ":"��",
                jiantou,
                alldirs["southeast"]=="          " ? "  ":"��");
                printf("             %10s  %-10s  %-10s\n",
                alldirs["southwest"],map_room,alldirs["southeast"]);
                
                        
        }       
        else
        {
                map_room2=env->query("short") ? env->query("short"): "----------";
                map_room=HIG+map_room2+NOR;
                for(i=0;i<(10-strlen(map_room2))/2;i++)
                        {
                                if(alldirs["east"]=="          ")
                                map_room =map_room + " ";
                                else map_room=map_room + "-";
                                if(alldirs["west"]=="          ")
                                map_room =" "+ map_room;
                                else map_room ="-"+map_room;
                        }
                printf("\n                            %s\n",map_room);
                
        }
        return;
}


int look_room(object me, object env)
{
	int i,n;
	object *inv,*ob,env1;
	mapping exits;
	string str,*dirs,*cdirs; 
	mixed *objs;

        int j, k, l;
        mapping *data;
    int amount;
    object obj,room;
        mixed *cmds;
    mapping my;
    string message,str2,modify,strrk;
        
        k = 0;
	data = allocate(3000);
	if( !env ) {
		write("������ܻ����ɵ�һƬ��ʲôҲû�С�\n");
		return 1;
	}

	str = sprintf( "$ct#%s\n",env->query("short"));
if (me->query_temp("xmud"))	str += sprintf( "$fln#%s\n",file_name(env));
if( mapp(exits = env->query("exits")) ) {
		dirs = keys(exits);
		dirs -= ({ 0 });
		if( sizeof(dirs)==0 )
			str += "    ����û���κ����Եĳ�·��\n";
		else if( sizeof(dirs)==1 ){
				str += "$exit#" + dirs[0] + ":"+exits[dirs[0]]->query("short")+"\n";
			}
		else
			{
				str += sprintf("$exit#%s|%s:",
				implode(dirs[0..sizeof(dirs)-2], "|"), dirs[sizeof(dirs)-1]);
str += sprintf("%s|%s\n",
                implode(map_array(values(exits)[0..sizeof(exits)-2], (: $1 = $1->query("short") :)), "|"), values(exits)[sizeof(dirs)-1]->query("short"));
		}	
}	


	inv = all_inventory(env);
	i=sizeof(inv);
	while(i--) {
		if( !me->visible(inv[i])) continue;
		if( inv[i]==me ) continue;
		if(inv[i]->is_character())
		{

strrk="";
   if( inv[i]->is_ghost() ) strrk = HIB "<����> " NOR + strrk;
 	 if (inv[i]->query_condition("killer")) strrk = HIR "<ͨ����> " NOR + strrk;
	 if( inv[i]->query_temp("sleepbag") ) strrk += HIR " <˯��˯����>" NOR;
   if(inv[i]->query("disable_type") && !living(inv[i]) )  strrk += HIR + inv[i]->query("disable_type") + NOR;
	 if( interactive(inv[i])	&&	query_idle( inv[i] ) > 120 ) strrk += HIM " <������>" NOR;
   if (inv[i]->is_fighting())  strrk = HIR " <ս����> " NOR + strrk;


		if (inv[i]->query("rider"))
			str +="$rw#"+inv[i]->name()+"("+inv[i]->query("id")+")" + "<"+inv[i]->query("rider") +strrk+">\n";
		else	
			str +="$rw#"+inv[i]->name()+"("+inv[i]->query("id")+")"+strrk+"\n";
		}
		else{
		if (inv[i]->query("rider"))
			str +="$cw#"+ inv[i]->name()+"("+inv[i]->query("id")+")" + "<"+inv[i]->query("rider") +strrk+">\n";
		else	
			str +="$cw#"+ inv[i]->name()+"("+inv[i]->query("id")+")"+strrk+"\n";
		}
		}
	str+="$#\n";
	//if (me->query("env/showmap")) realtime_map(me,env); 
	//str=BBLK"+str+"NOR;
	write(str);

str="";


	return 1;
}

int look_item(object me, object obj)
{
        mixed *inv;

        write(obj->long());
        inv = all_inventory(obj);
        if( sizeof(inv) ) {
                inv = map_array(inv, "inventory_look", this_object() );
                message("vision", sprintf("�����У�\n  %s\n",
                        implode(inv, "\n  ") ), me);
        }
        return 1;
}
string gettof(object me, object ob)
{
	object weapon;
	string skill_type,parry_type;
	int attack_points;
        if( objectp(weapon = ob->query_temp("weapon")) )
        {
                skill_type = weapon->query("skill_type");
                parry_type = "parry";
        }
        else
        {
                skill_type = "unarmed";
                parry_type = "unarmed";
        }

        attack_points = COMBAT_D->skill_power(ob, skill_type, SKILL_USAGE_ATTACK);
//        attack_points = ob->query_temp("apply/attack");
	return tough_level((int)(attack_points/100));
}
int look_living(object me, object obj)
{
        int per;
        int spi;
        int age;
        int weight;
        string str, limb_status, pro;
        mixed *inv;
        mapping my_fam, fam;
        int me_shen, obj_shen;
        int equip, wearornot;

        me_shen = (int)me->query("shen");
        obj_shen = (int)obj->query("shen");
        per = obj->query_per();
        age = obj->query("age");

        if(userp(obj) && me->query("combat_exp") < obj->query("combat_exp")/10 && me!= obj)
         {
        write("$renwu#"+"�Է���������̫�࣬��ñ��ҿ���С�ı���Ŷ��\n");
        return 1;
         }
        if(userp(obj) && me->query("shen") >0 && obj->query("shen")<0 && me!= obj)
         {
        write("$renwu#"+"����һ���������ɣ�һ����а�ɣ����ҿ������������á�\n");
        return 1;
         }
        if(userp(obj) && me->query("shen") <0 && obj->query("shen")>0 && me!= obj)
         {
        write("$renwu#"+"����һ���������ɣ�һ����а�ɣ����ҿ������������á�\n");
        return 1;
         }
        if(userp(obj) && obj->query("shen")< -100000 && me!= obj)
         {
        write("$renwu#"+"�Է��Ǹ���ħͷ���㻹���ҿ���С�ı�ɱŶ��\n");
        return 1;
         }

        if( me!=obj )
                message("vision", "$renwu#" + me->name() + "�������㿴����֪����Щʲô���⡣\n", obj);

        str = replace_string( obj->long(), "\n", "\n$renwu#")+"\n";
        pro = (obj==me) ? gender_self(obj->query("gender")) : gender_pronoun(obj->query("gender"));
	if (obj->query_temp("is_riding"))
                str += sprintf("$renwu#"+"%s������%s�ϣ���ͷ�����㡣\n", pro, obj->query_temp("is_riding"));

        if( (string)obj->query("race")=="����"
        &&      intp(obj->query("age")) )
        {
                str += sprintf("$renwu#"+"%s������Լ%s���ꡣ\n", pro, chinese_number(obj->query("age") / 10 * 10));
                str += sprintf("$renwu#"+"%s���书����", pro);
		str +=gettof(me,obj);
		str +=sprintf("��");
		str +=sprintf("�����ƺ�");
		str +=getdam(me,obj);
		str +=sprintf("��\n");
        }
        if(age > 70 ) per = per/4;
        if(age > 60 ) per = per/3;
        if(age > 50 ) per = per/2;
        if ((string) obj->query("gender") == "����" || (string) obj->query("gender") == "����")
        {
		   
                     if (per >=40) 
                        str +="$renwu#"+pro+ HIG"Ӣ�˲�����һ���˲ţ���Ϊ����������һ�ˣ�\n";
                if (per <= 39 && (per > 38))
                        str +="$renwu#"+pro+ HIG"���㿡�ţ���ò�Ƿ��������������\n";
                if (per <= 38 && (per > 37))
                        str +="$renwu#"+pro+ HIG"���ڷ����ʣ��������������������ٷ硣\n"NOR;
                if (per <= 37 && (per > 36))
                        str +="$renwu#"+pro+ HIG"����Ʈ�ݳ������������ס�\n"NOR;
                if (per <= 36 && (per > 35))
                        str +="$renwu#"+pro+ HIG"�����������񣬷�ױ����������������\n"NOR;
                if (per <= 35 && (per > 34))
                        str +="$renwu#"+pro+ HIG"���ڷ�������Ŀ�����ǣ����˹�Ŀ������\n"NOR;
                if (per <= 34 && (per > 33))
                        str +="$renwu#"+pro+ HIY"���ڷ����촽�����˿��Σ���ֹ�������ޡ�\n"NOR;
                if (per <= 33 && (per > 32))
                        str +="$renwu#"+pro+ HIY"����˫Ŀ���ǣ�ü�Ҵ��飬�������޲�Ϊ֮�Ķ���\n"NOR;
                if (per <= 32 && (per > 31))
                        str +="$renwu#"+pro+ HIY"���ھٶ���������ˮ�����̷��飬������������Ŀ�⡣\n"NOR;
                if (per <= 31 && (per > 30))
                        str +="$renwu#"+pro+ HIY"����˫�۹⻪Ө��͸���������ǵĹ�â��\n"NOR;
                if (per <= 30 && (per > 29))
                        str +="$renwu#"+pro+ HIY"����Ӣ���������������Ρ�\n"NOR;
                if (per <= 29 && (per > 28))
                        str +="$renwu#"+pro+ MAG"����Ŀ�Ƶ��ᣬ�ߴ�ͦ���������Ķ���\n"NOR;
                if (per <= 28 && (per > 27))
                        str +="$renwu#"+pro+ MAG"�����������£�����˹�ģ���ֹ�ʶȡ�\n"NOR;
                if (per <= 27 && (per > 26))
                        str +="$renwu#"+pro+ MAG"���ý�ü��Ŀ��Ӣ�˲������Ǳ�����\n"NOR;
                if (per <= 26 && (per > 25))
                        str +="$renwu#"+pro+ MAG"��������Ũ�ף����۱��ǣ��������ݣ������㵹��\n"NOR;
                if (per <= 25 && (per > 24))
                        str +="$renwu#"+pro+ MAG"����ü��˫�����������ǣ�Ӣͦ���ڡ�\n"NOR;
                if (per <= 24 && (per > 23))
                        str +="$renwu#"+pro+ CYN"���û���������׳��������Ӣ�˲�����\n"NOR;
                if (per <= 23 && (per > 22))
                        str +="$renwu#"+pro+ CYN"���÷�ɫ��𪣬�촽ī����˹������\n"NOR;
                if (per <= 22 && (per > 21))
                        str +="$renwu#"+pro+ CYN"����Ũü���ۣ��ߴ�ͦ�Σ�����������\n"NOR;
                if (per <= 21 && (per > 20))
                        str +="$renwu#"+pro+ CYN"���ñ�ֱ�ڷ��������������Գ������Ը�\n"NOR;
                if (per <= 20 && (per > 19))
                        str +="$renwu#"+pro+ CYN"����üĿ���㣬�����󷽣�һ���˲š�\n"NOR;
                if (per <= 19 && (per > 18))
                        str +="$renwu#"+pro+ YEL"������Բ���������ڷ����Ǹ񲻷���\n"NOR;
                if (per <= 18 && (per > 17))
                        str +="$renwu#"+pro+ YEL"������òƽƽ�������������ʲôӡ�ࡣ\n"NOR;
                if (per <= 17 && (per > 16))
                        str +="$renwu#"+pro+ YEL"���ð����Բ���������⣬���ζ��ࡣ\n"NOR;
                if (per <= 16 && (per > 15))
                        str +="$renwu#"+pro+ YEL"�����ͷ���룬����һ���Ͳ����øС�\n"NOR;
                if (per <= 15 && (per > 14))
                        str +="$renwu#"+pro+ YEL"����������ݣ�����ݹǣ�����Ҫ�����Ρ�\n"NOR;
                if (per <= 14 && (per > 13))
                        str +="$renwu#"+pro+ RED"���÷�ͷ�������Բ��ģ��ֽŶ̴֣����˷�Ц��\n"NOR;
                if (per <= 13 && (per > 12))
                        str +="$renwu#"+pro+ RED"������ü���ۣ�������ߣ�������״��\n"NOR;
                if (per <= 12 && (per > 11))
                        str +="$renwu#"+pro+ RED"���������Ƥ��ͷ���������˲����ٿ��ڶ��ۡ�\n"NOR;
                if (per <= 11 && (per > 10))
                        str +="$renwu#"+pro+ RED"�����������죬������ף�����ޱȡ�\n"NOR;
                if (per <= 10)
                        str +="$renwu#"+pro+ RED"����ü����б����ͷѢ�ţ�����������\n"NOR;
        }
        else
        {
            if ((string) obj->query("gender") == "Ů��")
            {
                if (per >= 40)
                {
                if(obj->query("describe"))
                {
             str += "$renwu#"+pro+"��������֮ò����ɫ���������޾��ף������˼����ӣ�\n"+(string)obj->query("describe")+"\n";
                }
            else
                        str += "$renwu#"+pro+"��������֮ò����ɫ���������޾��ף������˼����ӣ�\n�������ƣ�����ʤѩ���绪��������֪�㵹�˶���Ӣ�ۺ��ܡ�\n";
                }
                          if (per >=40) 
                        str +="$renwu#"+pro+ HIW"�������������ܣ������ƻã����޾��ף�ò������ʤ����\n"NOR;
                if (per <= 39 && (per > 38))
                        str +="$renwu#"+pro+ HIG"�������ף�������࣬���续�����ɣ�\n"NOR;
                if (per <= 38 && (per > 37))
                        str +="$renwu#"+pro+ HIG"���ڲ�����ϼ���������񣬻����������ӡ�\n"NOR;
                if (per <= 37 && (per > 36))
                        str +="$renwu#"+pro+ HIG"�����������������Ż���ɽ�����˼�֮���ס�\n"NOR;
                if (per <= 36 && (per > 35))
                        str +="$renwu#"+pro+ HIG"���ڷ����۰ף�Ӥ��С�ڣ�üĿ���飬�·�̫�����١�\n"NOR;
                if (per <= 35 && (per > 34))
                        str +="$renwu#"+pro+ HIG"�����������ģ����ȷ�����������Σ��۹�֬�ޡ�\n"NOR;
                if (per <= 34 && (per > 33))
                        str +="$renwu#"+pro+ HIY"�����������ã�ü��ī���������Ұ꣬Ŀ���ﲨ��\n"NOR;
                if (per <= 33 && (per > 32))
                        str +="$renwu#"+pro+ HIY"���ڷ�����ü�����溬�����������ݣ�ת�ζ��顣\n"NOR;
                if (per <= 32 && (per > 31))
                        str +="$renwu#"+pro+ HIY"����üĿ�续������ʤѩ�����ν�����߻���\n"NOR;
                if (per <= 31 && (per > 30))
                        str +="$renwu#"+pro+ HIY"���ڽ����������������£�����ܳ������㡣��\n"NOR;
                if (per <= 30 && (per > 29))
                        str +="$renwu#"+pro+ HIY"�����о���毻���ˮ���ж����������磬��̬��ǧ��\n"NOR;
            }
            else
            {
                if (living(obj))
		{
                if (!obj->query_temp("owner"))
                   str += "$renwu#"+pro+"��һֻδ��ѱ�����������۹������ǽ��ĺ͵��⡣\n";
                else
                   str += "$renwu#"+pro+"��һֻ��"+obj->query_temp("ownername")+"ѱ����������һ������ѱ�����ӡ�\n";
		}
            }
        }
        wearornot = 0;
        inv = all_inventory(obj);
        for(equip=0; equip<sizeof(inv); equip++)
        {
                if( inv[equip]->query("equipped") ) wearornot = 1;
        }
        //check about wife and husband
        if((obj->parse_command_id_list())[0]==me->query("couple/couple_id") )
        {
              if( (string)me->query("gender")=="Ů��" )
              {
                    str += sprintf("$renwu#"+"%s������ɷ�\n", pro);
              }
              else{
                    str += sprintf("$renwu#"+"%s��������ӡ�\n", pro);
              }
        }
                if (me->query("jiebai") && stringp(me->query("jiebai")))
        if (strsrch(me->query("jiebai"), obj->query("id")+">") >= 0)
        {
              if( obj->query("gender")=="Ů��" )
              {
                    if (obj->query("mud_age") > me->query("mud_age"))
                        str += sprintf("$renwu#"+"%s�������㡣\n", pro);
                    else
                        str += sprintf("$renwu#"+"%s����Ľ������ӡ�\n", pro);
              }
              else{
                    if (obj->query("mud_age") > me->query("mud_age"))
                        str += sprintf("$renwu#"+"%s����Ľ����ֳ���\n", pro);
                    else
                        str += sprintf("$renwu#"+"%s�������ܡ�\n", pro);
              }
        }
        if((wearornot == 0 ) && userp(obj) && !wizardp(obj) )
            str += "$renwu#"+pro+"���Ͼ�Ȼʲô��û��Ү��\n";
        // If we both has family, check if we have any relations.
        if( obj!=me
        &&      mapp(fam = obj->query("family"))
        &&      mapp(my_fam = me->query("family"))
        &&      fam["family_name"] == my_fam["family_name"] ) {

                if( fam["generation"]==my_fam["generation"] ) {

                        if( (string)obj->query("gender") == "����" ||
                                (string)obj->query("gender") == "����")
                                str += sprintf( "$renwu#"+pro + "�����%s%s��\n",
                                        my_fam["master_id"] == fam["master_id"]? "": "ͬ��",
                                        my_fam["enter_time"] > fam["enter_time"] ? "ʦ��": "ʦ��");
                        else
                                str += sprintf( "$renwu#"+pro + "�����%s%s��\n",
                                        my_fam["master_id"] == fam["master_id"]? "": "ͬ��",
                                        my_fam["enter_time"] > fam["enter_time"] ? "ʦ��": "ʦ��");
                } else if( fam["generation"] < my_fam["generation"] ) {
                        if( my_fam["master_id"] == obj->query("id") )
                                str += "$renwu#"+pro + "�����ʦ����\n";
                        else if( my_fam["generation"] - fam["generation"] > 1 )
                                str += "$renwu#"+pro + "�����ͬ�ų�����\n";
                        else if( fam["enter_time"] < my_fam["enter_time"] )
                                str += "$renwu#"+pro + "�����ʦ����\n";
                        else
                                str += "$renwu#"+pro + "�����ʦ�塣\n";
                } else {
                        if( fam["generation"] - my_fam["generation"] > 1 )
                                str += "$renwu#"+pro + "�����ͬ������\n";
                        else if( fam["master_id"] == me->query("id") )
                                str += "$renwu#"+pro + "����ĵ��ӡ�\n";
                        else
                                str += "$renwu#"+pro + "�����ʦֶ��\n";
                }
        }

        if( obj->query("max_qi") )
                str += "$renwu#"+pro + COMBAT_D->eff_status_msg((int)obj->query("eff_qi")* 100 / (int)obj->query("max_qi")) + "\n";

	if(obj->is_corpse() && obj->query("kantou") == 1) str += sprintf("$renwu#"+"%s��ͷ���������ˡ�\n", pro);

        inv = all_inventory(obj);
        if( sizeof(inv) ) {
                inv = map_array(inv, "inventory_look", this_object(), obj->is_corpse()? 0 : 1 );
                inv -= ({ 0 });
                if( sizeof(inv) )
                        str += sprintf( obj->is_corpse() ? "$renwu#"+"%s�������У�\n%s\n": "$renwu#"+"%s���ϴ�����\n""$renwu#"+"%s\n",
                                pro, implode(inv, "\n") );
        }
str+="$#\n";
        message("vision", "$renwu#"+str, me);

// Modified by Hop
        if( obj!=me && living(obj)
        && (((me_shen < -20000) && (obj_shen > 20000)) || ((me_shen > 20000) && (obj_shen < -20000)))
        && (((me_shen - obj_shen) > ((int)obj->query("neili") * 20))
        || ((obj_shen - me_shen) > ((int)obj->query("neili") * 20))))
        {
                write( obj->name() + "ͻȻת��ͷ������һ�ۡ�\n");
                if(obj->query("age") > 15 && me->query("age") > 15)
                   if(!wizardp(obj) && !wizardp(me))
                        COMBAT_D->auto_fight(obj, me, "berserk");
        }

        return 1;
}

string inventory_look(object obj, int flag)
{
        string str;

        str = obj->short();
        if( obj->query("equipped") )
                str = "$renwu#"+HIC "  ��" NOR + str;
        else if( !flag )
                str = "    " + str;
        else
                return 0;

        return str;
}

int look_room_item(object me, string arg)
{
        object env;
        mapping item, exits;

        if( !objectp(env = environment(me)) )
                return notify_fail("����ֻ�л����ɵ�һƬ��ʲôҲû�С�\n");
        if( mapp(item = env->query("item_desc")) && !undefinedp(item[arg]) ) {
                if( stringp(item[arg]) )
                        write(item[arg]);
                else if( functionp(item[arg]) )
                        write((string)(*item[arg])(me));

                return 1;
        }
        if( mapp(exits = env->query("exits")) && !undefinedp(exits[arg]) ) {
                if( objectp(env = find_object(exits[arg])) )
                        look_room(me, env);
                else {
                        call_other(exits[arg], "???");
                        look_room(me, find_object(exits[arg]));
                }
                return 1;
        }
        return notify_fail("��Ҫ��ʲô��\n");
}
string tough_level(int power)
{

	int lvl;
	int rawlvl;
	int grade = 1;
	if(power<0) power=0;
	rawlvl = (int) pow( (float) 1.0 * power, 0.3);
	lvl = to_int(rawlvl/grade);
                        if( lvl >= sizeof(tough_level_desc) )
                                lvl = sizeof(tough_level_desc)-1;
                        return tough_level_desc[((int)lvl)];
}
string getdam(object me, object obj)
{

	int level;
	level = obj->query_temp("apply/damage") + obj->query("jiali");
	level = level / 30;
                        if( level >= sizeof(heavy_level_desc) )
                                level = sizeof(heavy_level_desc)-1;
                        return heavy_level_desc[((int)level)];
}

int help (object me)
{
        write(@HELP
ָ���ʽ: look [<��Ʒ>|<����>|<����>]

���ָ������鿴�����ڵĻ�����ĳ����Ʒ��������Ƿ���

HELP
);
        return 1;
}

