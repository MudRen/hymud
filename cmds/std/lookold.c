// look.c
// colored by ReyGod in 1/10/1997 ----- I love colorful world :)
// ����6/16 ��ǰ�����ֺ�(find)��inventory.c�еļ��������ĳ�����
// ���look.c�м���Ҫ��һ���ݣ��ش˸�лfind��������

#include <room.h>
#include <ansi.h>
#include <combat.h>
#define TIME_TICK1 (time()*60)
//#define TIME_TICK1 (time()*60-900000000)
//#define TIME_TICK1 ((time()-900000000)*24)

inherit F_CLEAN_UP;

int look_room(object me, object env);
int look_item(object me, object obj);
int look_living(object me, object obj);
int look_room_item(object me, string arg);
string getper(object me, object obj);
string tough_level(int power);
string gettof(object me, object obj);
string getdam(object me, object obj);
string getwhere(object ob);
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

string w_power(int i)
{
	if( i >= 16 )	return HIY"����"NOR;
  if( i >= 15 )	return HIR"����"NOR;
	if( i >= 14 )	return HIR"����"NOR;
	if( i >= 13 )	return HIR"��Ԫ"NOR;	
	if( i >= 12 )	return HIR"��˫"NOR;	
	if( i >= 11 )	return HIM"����"NOR;	
	if( i >= 10 )	return HIY"��ʥ"NOR;
	if( i >= 9 )	return HIG"ħ��"NOR;
	if( i >= 8 )	return HIB"����"NOR;
	if( i >= 7 )	return HIC"����"NOR;
	if( i >= 6 )	return RED"����"NOR;
	if( i >= 5 )	return MAG"��׼"NOR;
	if( i >= 4 )	return YEL"�ܸ�"NOR;
	if( i >= 3 )	return GRN"�ֲ�"NOR;
	if( i >= 2 )	return BLU"ϸ��"NOR;
	if( i >=	1  )	return CYN"����"NOR;
	if( i <= 0 )	return "    ";
	return "    ";
}

string w_power2(int i)
{
	if( i >= 200 )	return HIY"����"NOR;
  if( i >= 180 )	return HIR"����"NOR;
	if( i >= 160 )	return HIR"����"NOR;
	if( i >= 130 )	return HIR"��Ԫ"NOR;	
	if( i >= 120 )	return HIR"��˫"NOR;	
	if( i >= 110 )	return HIM"����"NOR;	
	if( i >= 100 )	return HIY"��ʥ"NOR;
	if( i >= 90 )	return HIG"ħ��"NOR;
	if( i >= 80 )	return HIB"����"NOR;
	if( i >= 70 )	return HIC"����"NOR;
	if( i >= 60 )	return RED"����"NOR;
	if( i >= 50 )	return MAG"��׼"NOR;
	if( i >= 40 )	return YEL"�ܸ�"NOR;
	if( i >= 30 )	return GRN"�ֲ�"NOR;
	if( i >= 20 )	return BLU"ϸ��"NOR;
	if( i >	10  )	return CYN"����"NOR;
	if( i >	5  )	return YEL"һ��"NOR;
	if( i >=	1  )	return GRN"����"NOR;
	if( i <= 0 )	return "    ";
	return "    ";
}

void create() { seteuid(getuid()); }

int main(object me, string arg)
{
        object obj;
        int result;

        if( !arg ) result = look_room(me, environment(me));
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
     string *dirs,dirn;
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
                                dirn=dirs[i];
                                if (dirs[i]=="northeast") dirn="ne";
                                if (dirs[i]=="northwest") dirn="nw";
                                if (dirs[i]=="north") dirn="n";
                                if (dirs[i]=="northdown") dirn="nd";
                                if (dirs[i]=="northup") dirn="nu";
                                if (dirs[i]=="southeast") dirn="se";
                                if (dirs[i]=="southwest") dirn="sw";
                                if (dirs[i]=="south") dirn="s";
                                if (dirs[i]=="southdown") dirn="sd";
                                if (dirs[i]=="southup") dirn="su";
                                if (dirs[i]=="west") dirn="w";
                                if (dirs[i]=="westdown") dirn="wd";
                                if (dirs[i]=="westup") dirn="wu";
                                if (dirs[i]=="east") dirn="e";
                                if (dirs[i]=="eastdown") dirn="ed";
                                if (dirs[i]=="eastup") dirn="eu";
                                if (dirs[i]=="up") dirn="u";
                                if (dirs[i]=="down") dirn="d";
                              
                                if (room_obj->query("short"))
                                alldirs[dirs[i]]=room_obj->query("short")+"("+dirn+")";                              ;
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
    int i,amount,j, k, l;
            object *inv;
    object obj,room;
        mixed *cmds;
    mapping exits,my,*data;
    string str, *dirs,message,str2,modify,dest,str1,strrk;
    if( !env ) {
        write("������ܻ����ɵ�һƬ��ʲ��Ҳû�С�\n");
        return 1;
    }
    
if (userp(me) && me->query_temp("xmud"))
{
	str = sprintf( "$ct#%s\n",env->query("short"));

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
}
str="";    
        k = 0;
	data = allocate(3000);

    reset_eval_cost();
    if (!objectp(present("fire", me))  && environment(me)->query("outdoors") 
    && !wizardp(this_player()) 
    && this_player()->query("combat_exp",1) > 5000000
    &&   ((strsrch(CHINESE_D->chinese_date(TIME_TICK1), "��ʱ") >= 0) ||
         (strsrch(CHINESE_D->chinese_date(TIME_TICK1), "��ʱ") >= 0) ||
         (strsrch(CHINESE_D->chinese_date(TIME_TICK1), "��ʱ") >= 0) ||
         (strsrch(CHINESE_D->chinese_date(TIME_TICK1), "��ʱ") >= 0))
     ){
    str = sprintf( "%s"+NOR+BLU+"\n����  ҹ���ˣ�����Ȼ�������۾���ϸ�ۿ����ɻ��ǿ��������Χ�����\n"+
			"һ�ж���ҹɫ�����֣������µĵ�·��ģ��������...\n"+NOR+"",
        env->query("short"));

    if( mapp(exits = env->query("exits")) ) {
        dirs = keys(exits);
        for(i=0; i<sizeof(dirs); i++)
            if( (int)env->query_door(dirs[i], "status") & DOOR_CLOSED )
                dirs[i] = 0;
        dirs -= ({ 0 });
        if( sizeof(dirs)==0 )
            str += HIR + "    ����û���κ����Եĳ�·��\n"NOR;
    else if (!objectp(present("fire", me))  && environment(me)->query("outdoors") 
    && !wizardp(this_player()) 
    &&   ((strsrch(CHINESE_D->chinese_date(TIME_TICK1), "��ʱ") >= 0) ||
         (strsrch(CHINESE_D->chinese_date(TIME_TICK1), "��ʱ") >= 0) ||
         (strsrch(CHINESE_D->chinese_date(TIME_TICK1), "��ʱ") >= 0) ||
         (strsrch(CHINESE_D->chinese_date(TIME_TICK1), "��ʱ") >= 0)))
      str += BLU + "    ��ɫ̫���ˣ��㿴�������Եĳ�·��\n"NOR;
        else if( sizeof(dirs)==1 )
                        str += YEL + "    ����Ψһ�ĳ����� " + BOLD + dirs[0] + NOR + "��\n";
        else{
            dirs = sort_array(dirs,"sort_exits");
                        str += sprintf(  HIG + "    �������Ե�"+ HIC +"�����ڡ�"+ HIG +"��" + BOLD + "%s" + NOR + " " + HIG + "��  " + BOLD + "%s" + NOR + "��\n",
                              implode(dirs[0..sizeof(dirs)-2], "��"), dirs[sizeof(dirs)-1]);
        }
      }else
            str += "��������û���κ����Եĳ�·��\n";
        write(str);
        return 1;
    }
        if(env->query("outdoors",1))
                str2 = NOR+HIC"����"NOR;
        if(!env->query("outdoors",1))
                str2 = NOR+HIC"����"NOR;
    if (wizardp(me) && !me->query("env/show_room"))
    str = sprintf( HIC"��"HIW"%s"HIC"����%s"+NOR+" - "+RED+"%s\n"+NOR+"    %s",
        env->query("short"),str2,
        SECURITY_D->valid_read(file_name(env),me)? file_name(env): "",
        env->query("long"));
    else 
    str = sprintf(  HIC"��"HIW"%s"HIC"��  %s"+NOR+"\n    %s",env->query("short"),str2,env->query("long"));
           switch (NATURE_D->outdoor_room_outcolor())
        {
              case "BLK":
        str = sprintf( BLK + "��"+ "%s"+"��"+ NOR + " - %s %s\n    %s" + BLK + "%s" + NOR,
                env->query("short"),
                "����:"+getwhere(env),
                wizardp(me)? file_name(env): "",
                env->query("long"),
                env->query("outdoors")? NATURE_D->outdoor_room_description():"");
                   break;
              case "RED":
        str = sprintf( RED + "��"+ "%s"+"��"+ NOR + " - %s %s\n    %s" + RED + "%s" + NOR,
                env->query("short"),
                "����:"+getwhere(env),
                wizardp(me)? file_name(env): "",
                env->query("long"),
                env->query("outdoors")? NATURE_D->outdoor_room_description():"");
                   break;
              case "HIR":
        str = sprintf( HIR + "��"+ "%s"+"��"+ NOR + " - %s %s\n    %s" + HIR + "%s" + NOR,
                env->query("short"),
                "����:"+getwhere(env),
                wizardp(me)? file_name(env): "",
                env->query("long"),
                env->query("outdoors")? NATURE_D->outdoor_room_description():"");
                   break;
              case "GRN":
        str = sprintf( GRN + "��"+ "%s"+"��"+ NOR + " - %s %s\n    %s" + GRN + "%s" + NOR,
                env->query("short"),
                "����:"+getwhere(env),
                wizardp(me)? file_name(env): "",
                env->query("long"),
                env->query("outdoors")? NATURE_D->outdoor_room_description():"");
                   break;
              case "HIG":
        str = sprintf( HIG + "��"+ "%s"+"��"+ NOR + " - %s %s\n    %s" + HIG + "%s" + NOR,
                env->query("short"),
                "����:"+getwhere(env),
                wizardp(me)? file_name(env): "",
                env->query("long"),
                env->query("outdoors")? NATURE_D->outdoor_room_description():"");
                   break;
              case "YEL":
        str = sprintf( YEL + "��"+ "%s"+"��"+ NOR + " - %s %s\n    %s" + YEL + "%s" + NOR,
                env->query("short"),
                "����:"+getwhere(env),
                wizardp(me)? file_name(env): "",
                env->query("long"),
                env->query("outdoors")? NATURE_D->outdoor_room_description():"");
                   break;
              case "HIY":
        str = sprintf( HIY + "��"+ "%s"+"��"+ NOR + " - %s %s\n    %s" + HIY + "%s" + NOR,
                env->query("short"),
                "����:"+getwhere(env),
                wizardp(me)? file_name(env): "",
                env->query("long"),
                env->query("outdoors")? NATURE_D->outdoor_room_description():"");
                   break;
              case "BLU":
        str = sprintf( BLU + "��"+ "%s"+"��"+ NOR + " - %s %s\n    %s" + BLU + "%s" + NOR,
                env->query("short"),
                "����:"+getwhere(env),
                wizardp(me)? file_name(env): "",
                env->query("long"),
                env->query("outdoors")? NATURE_D->outdoor_room_description():"");
                   break;
              case "HIB":
        str = sprintf( HIB + "��"+ "%s"+"��"+ NOR + " - %s %s\n    %s" + HIB + "%s" + NOR,
                env->query("short"),
                "����:"+getwhere(env),
                wizardp(me)? file_name(env): "",
                env->query("long"),
                env->query("outdoors")? NATURE_D->outdoor_room_description():"");
                   break;
              case "MAG":
        str = sprintf( MAG + "��"+ "%s"+"��"+ NOR + " - %s %s\n    %s" + MAG + "%s" + NOR,
                env->query("short"),
                "����:"+getwhere(env),
                wizardp(me)? file_name(env): "",
                env->query("long"),
                env->query("outdoors")? NATURE_D->outdoor_room_description():"");
                   break;
              case "HIM":
        str = sprintf( HIM + "��"+ "%s"+"��"+ NOR + " - %s %s\n    %s" + HIM + "%s" + NOR,
                env->query("short"),
                "����:"+getwhere(env),
                wizardp(me)? file_name(env): "",
                env->query("long"),
                env->query("outdoors")? NATURE_D->outdoor_room_description():"");
                   break;
              case "CYN":
        str = sprintf( CYN + "��"+ "%s"+"��"+ NOR + " - %s %s\n    %s" + CYN + "%s" + NOR,
                env->query("short"),
                "����:"+getwhere(env),
                wizardp(me)? file_name(env): "",
                env->query("long"),
                env->query("outdoors")? NATURE_D->outdoor_room_description():"");
                   break;
              case "HIC":
        str = sprintf( HIC + "��"+ "%s"+"��"+ NOR + " - %s %s\n    %s" + HIC + "%s" + NOR,
                env->query("short"),
                "����:"+getwhere(env),
                wizardp(me)? file_name(env): "",
                env->query("long"),
                env->query("outdoors")? NATURE_D->outdoor_room_description():"");
                   break;
              case "WHT":
        str = sprintf( WHT + "��"+ "%s"+"��"+ NOR + " - %s %s\n    %s" + WHT + "%s" + NOR,
                env->query("short"),
                "����:"+getwhere(env),
                wizardp(me)? file_name(env): "",
                env->query("long"),
                env->query("outdoors")? NATURE_D->outdoor_room_description():"");
                   break;
              case "HIW":
        str = sprintf( HIW + "��"+ "%s"+"��"+ NOR + " - %s %s\n    %s" + HIW + "%s" + NOR,
                env->query("short"),
                "����:"+getwhere(env),
                wizardp(me)? file_name(env): "",
                env->query("long"),
                env->query("outdoors")? NATURE_D->outdoor_room_description():"");
                   break;
              default:
        str = sprintf( HIC + "��"+ "%s"+"��"+ NOR + " - %s %s\n    %s" + HIG + "%s" + NOR,
                env->query("short"),
                "����:"+getwhere(env),
                wizardp(me)? file_name(env): "",
                env->query("long"),
                env->query("outdoors")? NATURE_D->outdoor_room_description():"");
                   break;
	}
	
    if( wizardp(me) && mapp(exits = env->query("exits")) ) {
        dirs = keys(exits);
        for(i=0; i<sizeof(dirs); i++)
            if( (int)env->query_door(dirs[i], "status") & DOOR_CLOSED )
                dirs[i] = 0;
        dirs -= ({ 0 });
        if( mapp(exits) ){
            str +=HIG + "    �����"+ HIC +"�����ڡ�"+ HIG +"�У�"+ NOR + "\n";
            dirs =keys(exits);
            for (i=0;i<sizeof(exits);i++){
                if (!room=find_object(exits[dirs[i]]))
                room=load_object(exits[dirs[i]]);

/* 	if ( !room )
{
 dest=replace_string(exits[dirs[i]],"/entry","");
dest=replace_string(dest,"/exit","");
 if ( (room = find_object(dest)))
{
destruct(room);
load_object(dest);
//log_file("log", MUD_NAME + "Lookold �����Թ�����" + dest +"\n", 1);
}
room=load_object(exits[dirs[i]]);
}
*/

            if (room)   str+=sprintf(HIG + BOLD"����%-12s"+NOR+YEL+" --> "+CYN+"%-10s"+RED+"%s.c\n"+NOR,dirs[i],room->query("short"),exits[dirs[i]]);
            else    str+=sprintf(HIR +BOLD"����%-12s"+NOR+YEL+" --> "+RED+"û���������ڡ�"+dest+"\n"+NOR,dirs[i]);
            }}}else

    if( !wizardp(me) && mapp(exits = env->query("exits")) ) {
        dirs = keys(exits);
        for(i=0; i<sizeof(dirs); i++)
            if( (int)env->query_door(dirs[i], "status") & DOOR_CLOSED )
                dirs[i] = 0;
        dirs -= ({ 0 });
        if( mapp(exits) ){
str +=HIG + "    �����"+ HIC +"�����ڡ�"+ HIG +"�У�"+ NOR + "\n";
            dirs =keys(exits);
            for (i=0;i<sizeof(exits);i++){
                if (!room=find_object(exits[dirs[i]]))
                room=load_object(exits[dirs[i]]);
            if (room)
        str+=sprintf(HIG + BOLD"����%-12s"+NOR+YEL+" --> "+CYN+"%s"+RED+"\n"+NOR,dirs[i],room->query("short"));
            else
        str+=sprintf(HIR + BOLD"����%-12s"+NOR+YEL+" --> "+RED+"û���������ڡ�\n"+NOR,dirs[i]);
            }}}else

            str += HIR +"��������û���κ����Եĳ�·��"+NOR"+\n";

/*    i=0;
    foreach (obj in all_inventory(env)){
    if (!wizardp(me) && obj->query("no_show")) continue;
        if (!obj->is_character() && (i++)>99) continue;
        if (obj==me || !me->visible(obj) ){
            continue;
        }
        if (obj->query("money_id") 
            || !obj->query("unit")
            || obj->is_character()){
                if(!wizardp(me)){str+=sprintf("    %-12s\n",obj->short());}
                if(wizardp(me)){str+=sprintf("����%-28s" + YEL":"NOR + RED"%s" + ".c"NOR+ "\n",obj->short(),base_name(obj));}
            continue;
        }
        if (!mapp(my))
            my=([obj->query("unit")+obj->short():1]);
        else{
            amount=my[obj->query("unit")+obj->short()];
            my[obj->query("unit")+obj->short()]=amount+1;
        }
    }
    if (mapp(my)){
        dirs=keys(my);
        for (i=0;i<sizeof(my);i++)
                str+=sprintf("����%s%s\n",
my[dirs[i]]==1?"":CHINESE_D->chinese_number(my[dirs[i]]),
my[dirs[i]]==1?dirs[i][2..]:dirs[i]);
    }
    write(str);
    return 1;
} */
        inv = all_inventory(env);
		for (i = 0; i < sizeof(inv); i++) {
			if (inv[i]!=me 
			&&  me->visible(inv[i])
			&&  !inv[i]->query("money_id")
			&&  !inv[i]->query_temp("check_only"))
			{
				data[k]=([]);
				for(j = i; j < sizeof(inv); j++ )
				{
					if ( inv[i]->query("name")==inv[j]->query("name")
					&&   inv[i]->query("id")==inv[j]->query("id")
					&&   !inv[j]->query_temp("check_only") )
					{
						data[k]["id"]=inv[i]->short();
						data[k]["unit"]=inv[i]->query("unit");
						data[k]["num"]= data[k]["num"] + 1;
						inv[j]->set_temp("check_only", 1);
					}
					else continue;
				}
				k++;
			}
			else continue;
		}

		for (i = 0; i < sizeof(inv); i++) {
			if ( !inv[i]->query_temp("check_only") && inv[i]!=me && me->visible(inv[i]) )
			str += sprintf("%s%s\n", "  ", inv[i]->short());
		}

		for (i = 0; i < sizeof(inv); i++)
			if ( inv[i]->query_temp("check_only") )
				inv[i]->delete_temp("check_only");

		if (k > 0)
		{
			for (l = 0; l < k; l++)
				str = sprintf("%s%s%s\n", str,  (data[l]["num"]==1)? "  ":"  "+ chinese_number(data[l]["num"])+data[l]["unit"], data[l]["id"]);
		}
//
if (me->query_temp("xmud"))write ("��ͼ:\n");
realtime_map(me,env);              
if (me->query_temp("xmud"))
{
str1="$botten#";
str2="";
if (!environment(me)->query("roomif"))
{
	cmds = me->query_commands();
	for(i = 0; i<sizeof(cmds); i++) {
		if( cmds[i][2]==me ) continue;
		if(present(cmds[i][2], me)) continue;
  if (str1=="$botten#")
	str1 +=cmds[i][0];
	else str1 +="|"+cmds[i][0];
	}
  if (str1!="$botten#")
  str1 +=":";
	
	for(i = 0; i<sizeof(cmds); i++) {
		if( cmds[i][2]==me ) continue;
		if(present(cmds[i][2], me)) continue;
  if (str2=="")
	str2 +=cmds[i][0];
	else str2 +="|"+cmds[i][0];
	}
	
str1 +=str2;
str1 +="\n$#\n";

if (str2=="") str1="$botten#$#\n";
	write(str1);
}
}     

        write(str);

        return 1;
}

int look_item(object me, object obj)
{
        mixed *inv;
int sharpness,lev;
        write(obj->long());
        inv = all_inventory(obj);
        if( sizeof(inv) ) {
                inv = map_array(inv, "inventory_look", this_object() );
                message("vision", sprintf("�����У�\n  %s\n",
                        implode(inv, "\n  ") ), me);
        }
if (obj->query("makeritem")==1)
{
sharpness=obj->query("sharpness",1);
if (sharpness>=1) lev=1;
if (sharpness>=3) lev=2;
if (sharpness>=9) lev=3;
if (sharpness>=12) lev=4;
if (sharpness>=15) lev=5;
if (sharpness>=18) lev=6;
if (sharpness>=22) lev=7;
if (sharpness>=24) lev=8;

message("vision", sprintf("����һ��Ʒ��Ϊ"+chinese_number(lev)+"����������Ʒ ��������:\n"), me);
if (!obj->query("armor_type"))
{
	                message("vision", sprintf("����:"), me);
message("vision", sprintf(w_power2(obj->query("weapon_prop/intelligence"))), me);
	                message("vision", sprintf(" ����:"), me);
message("vision", sprintf(w_power2(obj->query("weapon_prop/strength"))), me);
message("vision", sprintf(" ��Դ:") ,me);
message("vision", sprintf(w_power2(obj->query("weapon_prop/karey"))), me);
message("vision", sprintf(" ����:"), me);
message("vision", sprintf(w_power2(obj->query("weapon_prop/percao"))), me);
message("vision", sprintf(" ��Ԩ:"), me);
message("vision", sprintf(w_power2(obj->query("weapon_prop/dexerity"))), me);
message("vision", sprintf(" ����:"), me);
message("vision", sprintf(w_power2(obj->query("weapon_prop/constitution"))), me);
message("vision", sprintf(" ��ʯ:"), me);
message("vision", sprintf(w_power2(obj->query("weapon_prop/dodge"))), me);
message("vision", sprintf(" ��ʯ:"), me);
message("vision", sprintf(w_power2(obj->query("weapon_prop/parry"))), me);
message("vision", sprintf("\n����:"), me);
message("vision", sprintf(w_power2(obj->query("weapon_prop/attack"))), me);
message("vision", sprintf(" ����:"), me);
message("vision", sprintf(w_power2(obj->query("weapon_prop/armor"))), me);
message("vision", sprintf(" ����:"), me);
message("vision", sprintf(w_power2(obj->query("weapon_prop/defense"))), me);
message("vision", sprintf(" ����:"), me);
message("vision", sprintf(w_power2(obj->query("weapon_prop/neili"))), me);
message("vision", sprintf(" ����:"), me);
message("vision", sprintf(w_power2(obj->query("weapon_prop/qi"))), me);
message("vision", sprintf(" ����:"), me);
message("vision", sprintf(w_power2(obj->query("weapon_prop/jing"))), me);
message("vision", sprintf(" ����:"), me);
message("vision", sprintf(w_power2(obj->query("weapon_prop/jingli"))), me);
message("vision", sprintf(" ����:"), me);
message("vision", sprintf(w_power2(obj->query("weapon_prop/damage"))), me);
}
else
{
	                message("vision", sprintf("����:"), me);
message("vision", sprintf(w_power2(obj->query("armor_prop/intelligence"))), me);
	                message("vision", sprintf(" ����:"), me);
message("vision", sprintf(w_power2(obj->query("armor_prop/strength"))), me);
message("vision", sprintf(" ��Դ:") ,me);
message("vision", sprintf(w_power2(obj->query("armor_prop/karey"))), me);
message("vision", sprintf(" ����:"), me);
message("vision", sprintf(w_power2(obj->query("armor_prop/percao"))), me);
message("vision", sprintf(" ��Ԩ:"), me);
message("vision", sprintf(w_power2(obj->query("armor_prop/dexerity"))), me);
message("vision", sprintf(" ����:"), me);
message("vision", sprintf(w_power2(obj->query("armor_prop/constitution"))), me);
message("vision", sprintf(" ��ʯ:"), me);
message("vision", sprintf(w_power2(obj->query("armor_prop/dodge"))), me);
message("vision", sprintf(" ��ʯ:"), me);
message("vision", sprintf(w_power2(obj->query("armor_prop/parry"))), me);
message("vision", sprintf("\n����:"), me);
message("vision", sprintf(w_power2(obj->query("armor_prop/attack"))), me);
message("vision", sprintf(" ����:"), me);
message("vision", sprintf(w_power2(obj->query("armor_prop/armor"))), me);
message("vision", sprintf(" ����:"), me);
message("vision", sprintf(w_power2(obj->query("armor_prop/defense"))), me);
message("vision", sprintf(" ����:"), me);
message("vision", sprintf(w_power2(obj->query("armor_prop/neili"))), me);
message("vision", sprintf(" ����:"), me);
message("vision", sprintf(w_power2(obj->query("armor_prop/qi"))), me);
message("vision", sprintf(" ����:"), me);
message("vision", sprintf(w_power2(obj->query("armor_prop/jing"))), me);
message("vision", sprintf(" ����:"), me);
message("vision", sprintf(w_power2(obj->query("armor_prop/jingli"))), me);
message("vision", sprintf(" ����:"), me);
message("vision", sprintf(w_power2(obj->query("armor_prop/damage"))), me);	
}		
	                message("vision", sprintf("\n����һ���������Ʒ ��������:\n"), me);
	                message("vision", sprintf("��:"), me);
message("vision", sprintf(w_power(obj->query("wtypeA"))), me);
	                message("vision", sprintf(" ľ:"), me);
message("vision", sprintf(w_power(obj->query("wtypeB"))), me);
message("vision", sprintf(" ˮ:") ,me);
message("vision", sprintf(w_power(obj->query("wtypeC"))), me);
message("vision", sprintf(" ��:"), me);
message("vision", sprintf(w_power(obj->query("wtypeD"))), me);
message("vision", sprintf(" ��:"), me);
message("vision", sprintf(w_power(obj->query("wtypeE"))), me);
message("vision", sprintf(" ��:"), me);
message("vision", sprintf(w_power(obj->query("wtypeF"))), me);
message("vision", sprintf("\n��:"), me);
message("vision", sprintf(w_power(obj->query("wtypeG"))), me);
message("vision", sprintf(" ��:"), me);
message("vision", sprintf(w_power(obj->query("wtypeH"))), me);
message("vision", sprintf(" ��:"), me);
message("vision", sprintf(w_power(obj->query("wtypeI"))), me);
message("vision", sprintf(" ��:"), me);
message("vision", sprintf(w_power(obj->query("wtypeJ"))), me);
message("vision", sprintf(" ��:"), me);
message("vision", sprintf(w_power(obj->query("wtypeK"))), me);
message("vision", sprintf(" ħ:"), me);
message("vision", sprintf(w_power(obj->query("wtypeL"))), me);
message("vision", sprintf("\n"), me);



}	
        return 1;
}
string gettof(object me, object ob)
{
	object weapon;
	string skill_type,parry_type;
	mapping prepare;
	int attack_points;
    if( objectp(weapon = ob->query_temp("weapon")) )
        {
                skill_type = weapon->query("skill_type");
        }
        else
        {
                prepare = ob->query_skill_prepare();
                if (!sizeof(prepare)) skill_type = "unarmed";
                else skill_type = keys(prepare)[0];   
	    }
        attack_points = COMBAT_D->skill_power(ob, skill_type, SKILL_USAGE_ATTACK);
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

        if( me!=obj )
                message("vision", me->name() + "�������㿴����֪����Щʲô���⡣\n", obj);

        str = obj->long();
        pro = (obj==me) ? gender_self(obj->query("gender")) : gender_pronoun(obj->query("gender"));
	    if (age>50) per = per*2/3;
		if (obj->query_temp("is_riding"))
                str += sprintf("%s������%s�ϣ���ͷ�����㡣\n", pro, obj->query_temp("is_riding"));

        if( (string)obj->query("race")=="����"
        &&      intp(obj->query("age")) )
        {       if(wizardp(obj))
			str+=sprintf(HIY"%sȫ��ɢ����ҫ�۵Ľ�⣬����������֮������ࡣ\n"NOR,pro);
                str += sprintf("%s������Լ%s���꣬", pro, chinese_number(obj->query("age") / 10 * 10));
                  if ((string) obj->query("gender") == "����" || (string) obj->query("gender") == "����")
        {
		   
                     if (per >=40) 
                        str +=pro+ HIG"Ӣ�˲�����һ���˲ţ���Ϊ����������һ�ˣ�\n";
                if (per <= 39 && (per > 38))
                        str +=pro+ HIG"���㿡�ţ���ò�Ƿ��������������\n";
                if (per <= 38 && (per > 37))
                        str +=pro+ HIG"���ڷ����ʣ��������������������ٷ硣\n"NOR;
                if (per <= 37 && (per > 36))
                        str +=pro+ HIG"����Ʈ�ݳ������������ס�\n"NOR;
                if (per <= 36 && (per > 35))
                        str +=pro+ HIG"�����������񣬷�ױ����������������\n"NOR;
                if (per <= 35 && (per > 34))
                        str +=pro+ HIG"���ڷ�������Ŀ�����ǣ����˹�Ŀ������\n"NOR;
                if (per <= 34 && (per > 33))
                        str +=pro+ HIY"���ڷ����촽�����˿��Σ���ֹ�������ޡ�\n"NOR;
                if (per <= 33 && (per > 32))
                        str +=pro+ HIY"����˫Ŀ���ǣ�ü�Ҵ��飬�������޲�Ϊ֮�Ķ���\n"NOR;
                if (per <= 32 && (per > 31))
                        str +=pro+ HIY"���ھٶ���������ˮ�����̷��飬������������Ŀ�⡣\n"NOR;
                if (per <= 31 && (per > 30))
                        str +=pro+ HIY"����˫�۹⻪Ө��͸���������ǵĹ�â��\n"NOR;
                if (per <= 30 && (per > 29))
                        str +=pro+ HIY"����Ӣ���������������Ρ�\n"NOR;
                if (per <= 29 && (per > 28))
                        str +=pro+ MAG"����Ŀ�Ƶ��ᣬ�ߴ�ͦ���������Ķ���\n"NOR;
                if (per <= 28 && (per > 27))
                        str +=pro+ MAG"�����������£�����˹�ģ���ֹ�ʶȡ�\n"NOR;
                if (per <= 27 && (per > 26))
                        str +=pro+ MAG"���ý�ü��Ŀ��Ӣ�˲������Ǳ�����\n"NOR;
                if (per <= 26 && (per > 25))
                        str +=pro+ MAG"��������Ũ�ף����۱��ǣ��������ݣ������㵹��\n"NOR;
                if (per <= 25 && (per > 24))
                        str +=pro+ MAG"����ü��˫�����������ǣ�Ӣͦ���ڡ�\n"NOR;
                if (per <= 24 && (per > 23))
                        str +=pro+ CYN"���û���������׳��������Ӣ�˲�����\n"NOR;
                if (per <= 23 && (per > 22))
                        str +=pro+ CYN"���÷�ɫ��𪣬�촽ī����˹������\n"NOR;
                if (per <= 22 && (per > 21))
                        str +=pro+ CYN"����Ũü���ۣ��ߴ�ͦ�Σ�����������\n"NOR;
                if (per <= 21 && (per > 20))
                        str +=pro+ CYN"���ñ�ֱ�ڷ��������������Գ������Ը�\n"NOR;
                if (per <= 20 && (per > 19))
                        str +=pro+ CYN"����üĿ���㣬�����󷽣�һ���˲š�\n"NOR;
                if (per <= 19 && (per > 18))
                        str +=pro+ YEL"������Բ���������ڷ����Ǹ񲻷���\n"NOR;
                if (per <= 18 && (per > 17))
                        str +=pro+ YEL"������òƽƽ�������������ʲôӡ�ࡣ\n"NOR;
                if (per <= 17 && (per > 16))
                        str +=pro+ YEL"���ð����Բ���������⣬���ζ��ࡣ\n"NOR;
                if (per <= 16 && (per > 15))
                        str +=pro+ YEL"�����ͷ���룬����һ���Ͳ����øС�\n"NOR;
                if (per <= 15 && (per > 14))
                        str +=pro+ YEL"����������ݣ�����ݹǣ�����Ҫ�����Ρ�\n"NOR;
                if (per <= 14 && (per > 13))
                        str +=pro+ RED"���÷�ͷ�������Բ��ģ��ֽŶ̴֣����˷�Ц��\n"NOR;
                if (per <= 13 && (per > 12))
                        str +=pro+ RED"������ü���ۣ�������ߣ�������״��\n"NOR;
                if (per <= 12 && (per > 11))
                        str +=pro+ RED"���������Ƥ��ͷ���������˲����ٿ��ڶ��ۡ�\n"NOR;
                if (per <= 11 && (per > 10))
                        str +=pro+ RED"�����������죬������ף�����ޱȡ�\n"NOR;
                if (per <= 10)
                        str +=pro+ RED"����ü����б����ͷѢ�ţ�����������\n"NOR;
        }
        else
        {
            if ((string) obj->query("gender") == "Ů��")
            {
                if (per >=40) 
                        str +=pro+ HIW"�������������ܣ������ƻã����޾��ף�ò������ʤ����\n"NOR;
                if (per <= 39 && (per > 38))
                        str +=pro+ HIG"�������ף�������࣬���续�����ɣ�\n"NOR;
                if (per <= 38 && (per > 37))
                        str +=pro+ HIG"���ڲ�����ϼ���������񣬻����������ӡ�\n"NOR;
                if (per <= 37 && (per > 36))
                        str +=pro+ HIG"�����������������Ż���ɽ�����˼�֮���ס�\n"NOR;
                if (per <= 36 && (per > 35))
                        str +=pro+ HIG"���ڷ����۰ף�Ӥ��С�ڣ�üĿ���飬�·�̫�����١�\n"NOR;
                if (per <= 35 && (per > 34))
                        str +=pro+ HIG"�����������ģ����ȷ�����������Σ��۹�֬�ޡ�\n"NOR;
                if (per <= 34 && (per > 33))
                        str +=pro+ HIY"�����������ã�ü��ī���������Ұ꣬Ŀ���ﲨ��\n"NOR;
                if (per <= 33 && (per > 32))
                        str +=pro+ HIY"���ڷ�����ü�����溬�����������ݣ�ת�ζ��顣\n"NOR;
                if (per <= 32 && (per > 31))
                        str +=pro+ HIY"����üĿ�续������ʤѩ�����ν�����߻���\n"NOR;
                if (per <= 31 && (per > 30))
                        str +=pro+ HIY"���ڽ����������������£�����ܳ������㡣��\n"NOR;
                if (per <= 30 && (per > 29))
                        str +=pro+ HIY"�����о���毻���ˮ���ж����������磬��̬��ǧ��\n"NOR;
                if (per <= 29 && (per > 28))
                        str +=pro+ MAG"���ý�С���磬��������������������ˡ�\n"NOR;
                if (per <= 28 && (per > 27))
                        str +=pro+ MAG"����Ѽ��������������ü���ڷ����٣��������֡�\n"NOR;
                if (per <= 27 && (per > 26))
                        str +=pro+ MAG"��������ϸ����������������Ķ��ˣ�������ɡ�\n"NOR;
                if (per <= 26 && (per > 25))
                        str +=pro+ MAG"���÷���ϸ������欶��ˣ�����һ�����������ѡ�\n";
                if (per <= 25 && (per > 24))
                        str +=pro+ MAG"���÷��۰���������ҩ���̣����￴����\n"NOR;
                if (per <= 24 && (per > 23))
                        str +=pro+ CYN"������������Ŀ����ˮ��ǧ�����ġ�\n"NOR;
                if (per <= 23 && (per > 22))
                        str +=pro+ CYN"�����������ģ�����Ө͸��������˼��\n"NOR;
                if (per <= 22 && (per > 21))
                        str +=pro+ CYN"������Ц��Ȼ����Լ���ˡ�\n"NOR;
                if (per <= 21 && (per > 20))
                        str +=pro+ CYN"�������滨��¶������������\n"NOR;
                if (per <= 20 && (per > 19))
                        str +=pro+ CYN"���÷��˳������������ˡ�\n"NOR;
                if (per <= 19 && (per > 18))
                        str +=pro+ YEL"���ü���΢�ᣬ�ŵ��������¿��ˡ�\n"NOR;
                if (per <= 18 && (per > 17))
                        str +=pro+ YEL"�����䲻���£���Ҳ�׾�����Щ����֮����\n"NOR;
                if (per <= 17 && (per > 16))
                        str +=pro+ YEL"���������С�������޹⣬��������\n"NOR;
                if (per <= 16 && (per > 15))
                        str +=pro+ YEL"���øɻƿ��ݣ���ɫ���ƣ�����Ů��ζ��\n"NOR;
                if (per <= 15 && (per > 14))
                        str +=pro+ YEL"�����������Ƥɫ�ֺڣ���ª������\n"NOR;
                if (per <= 14 && (per > 13))
                        str +=pro+ RED"����һ�����������һ����û�øС�\n"NOR;
                if (per <= 13 && (per > 12))
                        str +=pro+ RED"������С�綹��üëϡ�裬�����צ������������\n"NOR;
                if (per <= 12 && (per > 11))
                        str +=pro+ RED"���ð���ü�������ۣ���Ƥ�Ʒ�������һ�������¡�\n"NOR;
                if (per <= 11 && (per > 10))
                        str +=pro+ RED"�������б�ۣ���ɫ�Ұܣ�ֱ����һ�㡣\n"NOR;
	         if (per <=10) 
                        str +=pro+ RED"���ó������Σ�״��ҹ�棬Ů�˳������������������硣\n"NOR;
            }
            else
            {
                if (living(obj))
		{
                if (!obj->query_temp("owner"))
                   str += pro+"��һֻδ��ѱ�����������۹������ǽ��ĺ͵��⡣\n";
                else
                   str += pro+"��һֻ��"+obj->query_temp("ownername")+"ѱ����������һ������ѱ�����ӡ�\n";
		}
            }
        }
				str += sprintf("%s���书����", pro);
		str +=gettof(me,obj);
		str +=sprintf("��");
		str +=sprintf("�����ƺ�");
		str +=getdam(me,obj);
		str +=sprintf("��\n");
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
                    str += sprintf("%s������ɷ�\n", pro);
              }
              else{
                    str += sprintf("%s��������ӡ�\n", pro);
              }
        }
        if (me->query("jiebai") && stringp(me->query("jiebai")))
        if (strsrch(me->query("jiebai"), obj->query("id")+">") >= 0)
        {
              if( obj->query("gender")=="Ů��" )
              {
                    if (obj->query("mud_age") > me->query("mud_age"))
                        str += sprintf("%s�������㡣\n", pro);
                    else
                        str += sprintf("%s����Ľ������ӡ�\n", pro);
              }
              else{
                    if (obj->query("mud_age") > me->query("mud_age"))
                        str += sprintf("%s����Ľ����ֳ���\n", pro);
                    else
                        str += sprintf("%s�������ܡ�\n", pro);
              }
        }
        if((wearornot == 0 ) && userp(obj) && !wizardp(obj) )
            str += pro+"���Ͼ�Ȼʲô��û��Ү��\n";
        if (!sizeof(inv) && me != obj && obj->query("race")=="����")
                str += pro + "����û���κ�װ����\n";

        // If we both has family, check if we have any relations.
        if( obj!=me
        &&      mapp(fam = obj->query("family"))
        &&      mapp(my_fam = me->query("family"))
        &&      fam["family_name"] == my_fam["family_name"] ) {

                if( fam["generation"]==my_fam["generation"] ) {

                        if( (string)obj->query("gender") == "����" ||
                                (string)obj->query("gender") == "����")
                                str += sprintf( pro + "�����%s%s��\n",
                                        my_fam["master_id"] == fam["master_id"]? "": "ͬ��",
                                        my_fam["enter_time"] > fam["enter_time"] ? "ʦ��": "ʦ��");
                        else
                                str += sprintf( pro + "�����%s%s��\n",
                                        my_fam["master_id"] == fam["master_id"]? "": "ͬ��",
                                        my_fam["enter_time"] > fam["enter_time"] ? "ʦ��": "ʦ��");
                } else if( fam["generation"] < my_fam["generation"] ) {
                        if( my_fam["master_id"] == obj->query("id") )
                                str += pro + "�����ʦ����\n";
                        else if( my_fam["generation"] - fam["generation"] > 1 )
                                str += pro + "�����ͬ�ų�����\n";
                        else if( fam["enter_time"] < my_fam["enter_time"] )
                                str += pro + "�����ʦ����\n";
                        else
                                str += pro + "�����ʦ�塣\n";
                } else {
                        if( fam["generation"] - my_fam["generation"] > 1 )
                                str += pro + "�����ͬ������\n";
                        else if( fam["master_id"] == me->query("id") )
                                str += pro + "����ĵ��ӡ�\n";
                        else
                                str += pro + "�����ʦֶ��\n";
                }
        }

        if( obj->query("max_qi") )
                str += pro + COMBAT_D->eff_status_msg((int)obj->query("eff_qi")* 100 / (int)obj->query("max_qi")) + "\n";

	if(obj->is_corpse() && obj->query("kantou") == 1) str += sprintf("%s��ͷ���������ˡ�\n", pro);

        inv = all_inventory(obj);
        if( sizeof(inv) ) {
                inv = map_array(inv, "inventory_look", this_object(), obj->is_corpse()? 0 : 1 );
                inv -= ({ 0 });
                if( sizeof(inv) )
                        str += sprintf( obj->is_corpse() ? "%s�������У�\n%s\n": "%s����װ������\n%s\n",
                                pro, implode(inv, "\n") );
        }
        if (!sizeof(inv) && me != obj && obj->query("race")=="����")
                str += pro + "����û���κ�װ����\n";

        message("vision", str, me);

// Modified by Hop
/*
        if( obj!=me
        &&      living(obj)
        &&      random((int)obj->query("shen")) < 0 - (int)me->query("int") * 10 ) {
                write( obj->name() + "ͻȻת��ͷ������һ�ۡ�\n");
                COMBAT_D->auto_fight(obj, me, "berserk");
        }
*/
        if( obj!=me && living(obj)
        && (((me_shen < 0) && (obj_shen > 0)) || ((me_shen > 0) && (obj_shen < 0)))
        && (((me_shen - obj_shen) > ((int)obj->query("neili") * 20))
        || ((obj_shen - me_shen) > ((int)obj->query("neili") * 20))))
        {
                write( obj->name() + "ͻȻת��ͷ������һ�ۡ�\n");
                if(obj->query("age") > 17 && me->query("age") > 17)
                   if(!wizardp(obj) && !wizardp(me) && !userp(obj))
                        COMBAT_D->auto_fight(obj, me, "berserk");
        }

        return 1;
}

string inventory_look(object obj, int flag)
{
        string str;

        str = obj->short();
        if( obj->query("equipped") )
                str = HIC "  ��" NOR + str;
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
	level = obj->query_temp("apply/damage") / 2 + obj->query("jiali");
        if (!level) level=30;
	level = level / 30;
                        if( level >= sizeof(heavy_level_desc) )
                                level = sizeof(heavy_level_desc)-1;
                        return heavy_level_desc[((int)level)];
}


string getwhere(object ob)
{
       object tmpobj,where, *ob_list,me,obtwo,obthree,tob;

        object item,room;

        string output,outputt,dis,alt,dir,local,tlocal,ck,playout;
        
        int i;

        int x,y,z,x0,y0,z0;

        int realdis;
	 mixed map,mapt;

        int tmp;
        string *dir1;
        string *dir2;

	string str="";
output="δ֪����";

dir2=explode(base_name(ob),"/");

if (dir2[1]=="baituo")  

output="����ɽ";

else if (dir2[1]=="binghuodao")  

	output="����";

else if (dir2[1]=="city")  

	output="����";

else if (dir2[1]=="city2" || dir2[1]=="beijing"  || dir2[1]=="huanggon"  || dir2[1]=="huanggong" || dir2[1]=="beihai")  

	output="������";

else if (dir2[1]=="city4" || dir2[1]=="changan")   

	output="������";

else if (dir2[1]=="dali")  

	output="����";

else if (dir2[1]=="emei")  

	output="��üɽ";

else if (dir2[1]=="foshan")  

	output="��ɽ";

else if (dir2[1]=="gaibang")  

	output="ؤ��";

else if (dir2[1]=="gaochang")  

	output="�߲��Թ�";

else if (dir2[1]=="guanwai")  

	output="����";

else if (dir2[1]=="guiyun")  

	output="����ׯ";

else if (dir2[1]=="gumu")  

	output="��Ĺ��";

else if (dir2[1]=="hangzhou")  

	output="����";

else if (dir2[1]=="heimuya")  

	output="��ľ��";

else if (dir2[1]=="hengshan")  

	output="��ɽ";

else if (dir2[1]=="henshan")  

	output="��ɽ";

else if (dir2[1]=="huanghe")  

	output="�ƺӾ���";

else if (dir2[1]=="huashan")  

	output="��ɽ";

else if (dir2[1]=="jinshe")  

	output="����ɽ��";

else if (dir2[1]=="lingjiu")  

	output="���չ�";

else if (dir2[1]=="lingzhou")  

	output="����";

else if (dir2[1]=="meizhuang")  

	output="÷ׯ";

else if (dir2[1]=="mingjiao")  

	output="����";

else if (dir2[1]=="qingcheng")  

	output="���ɽ";

else if (dir2[1]=="quanzhen")  

	output="ȫ����";

else if (dir2[1]=="quanzhou")  

	output="Ȫ��";

else if (dir2[1]=="shaolin")  

	output="������";

else if (dir2[1]=="shenlong")  

	output="������";

else if (dir2[1]=="songshan")  

	output="��ɽ";

else if (dir2[1]=="suzhou")  

	output="����";

else if (dir2[1]=="taishan")  

	output="̩ɽ";

else if (dir2[1]=="taohua")  

	output="�һ���";

else if (dir2[1]=="tianlongsi")  

	output="������";

else if (dir2[1]=="wanjiegu")  

	output="��ٹ�";

else if (dir2[1]=="wudang")  

	output="�䵱ɽ";

else if (dir2[1]=="xiakedao")  

	output="���͵�";

else if (dir2[1]=="xiangyang")  

	output="������";

else if (dir2[1]=="xiaoyao")  

	output="��ң��";

else if (dir2[1]=="xingxiu")  

	output="���޺�";

else if (dir2[1]=="xueshan")  

	output="ѩɽ��";

else if (dir2[1]=="xuedao")  

	output="��ѩɽ";

else if (dir2[1]=="mr")  

	output="Ľ������";

else if (dir2[1]=="kunlun")  

	output="����ɽ";

else if (dir2[1]=="tiezhang")  

	output="������";

else if (dir2[1]=="huizhu")  

	output="���岿��";

else if (dir2[1]=="yinju")  

	output="һ�ƴ�ʦ��";

else if (dir2[1]=="menggu")  

	output="�ɹŲ�ԭ";

else if (dir2[1]=="qianjin")  

	output="����ǧ��¥";

else if (dir2[1]=="lingshedao")  

	output="���ߵ�";

else if (dir2[1]=="ruzhou")  

	output="���ݳ�";

else if (dir2[1]=="kunming")  

	output="����";

else if (dir2[1]=="jingzhou")  

	output="����";

else if (dir2[1]=="yanjing")  

	output="�ྩ";

else if (dir2[1]=="lanzhou" || dir2[1]=="lanzhouchen")  

	output="����";

else if (dir2[1]=="jyguan")  

	output="��������";

else if (dir2[1]=="changcheng")  

	output="������";

else if (dir2[1]=="fairyland")  

	output="��÷ɽׯ";

else if (dir2[1]=="sdxl")  

	output="��ħ�������Ĺ";

else if (dir2[1]=="jqg")  

	output="�����";

else if (dir2[1]=="nio")  

	output="ţ�Ҵ�";

else if (dir2[1]=="feihu")  

	output="��������";

else if (dir2[1]=="wuguan")  

	output="�������";

else if (dir2[1]=="village")  

	output="��ɽ��";

else if (dir2[1]=="taohuacun")  

	output="�һ���";

else if (dir2[1]=="pingan")  

	output="ƽ����";

else if (dir2[1]=="lingxiao")  

	output="������";

else if (dir2[1]=="wudujiao")  

	output="�嶾��";

else if (dir2[1]=="hj")  

	output="��ɽ������ԭ";
else if (dir2[1]=="dali/yuxu")  

	output="���������";
else if (dir2[1]=="dali/wuliang")  

	output="��������ɽ";
else if (dir2[1]=="huanghe/yyd")  

	output="�ƺ�����";
else if (dir2[1]=="kaifeng")  

	output="�����";
else if (dir2[1]=="feitian")  

	output="����������";
else if (dir2[1]=="japan")  

	output="�ձ���";
else if (dir2[1]=="tangmen")  

	output="����";
else if (dir2[1]=="luoyang")  

	output="������";

else if (dir2[1]=="chengdu" || dir2[1]=="city3")  

	output="�ɶ�";

else if (dir2[1]=="baihuagu")  

	output="�ٻ���";

else if (dir2[1]=="heizhao")  

	output="����";

else if (dir2[1]=="jiaxing")  

	output="����";

else if (dir2[1]=="shiliang")  

	output="�¼�ׯ";

else if (dir2[1]=="wuyi")  

	output="����ɽ��";

else if (dir2[1]=="yanping")  

	output="��ƽ��";
	

if (dir2[1]=="jiangling")  
{
	output="�����";
}

if (dir2[1]=="yueyang")  
{
	output="������";	
}

if (dir2[1]=="qilian")  
{
	output="����ɽ";	
}

if (dir2[1]=="shouxihu")  
{
	output="������";	
}

if (dir2[1]=="wuxi")  
{
	output="������";	
}

if (dir2[1]=="yixing")  
{
	output="���˳�";	
}
if (dir2[1]=="taiwan")  
{
	output="̨�����";	
}
if (dir2[1]=="nanyang")  
{
	output="��������";	
}
if (dir2[1]=="nanshaolin")  
{
	output="�����ֵ���";	
}

if (dir2[1]=="cangzhou")  
{
	output="���ݵ���";	
}

if (dir2[1]=="tanggu")  
{
	output="�����ǵ���";	
}

if (dir2[1]=="yunhe")  
{
	output="�������˺�";	
}

if (dir2[1]=="hainan")  
{
	output="���ϵ�";	
}

if (dir2[1]=="jindezheng")  
{
	output="������";	
}

if (dir2[1]=="yandang")  
{
	output="�㵴ɽ";	
}

if (dir2[1]=="jinling")  
{
	output="�����";	
}

if (dir2[1]=="sandboy")  
{
	output="����ũ��";	
}

if (dir2[1]=="huangshan")  
{
	output="��ɽ";	
}

if (dir2[1]=="yubifeng")  
{
	output="��ʷ�";	
}

if (dir2[1]=="quanzhouchen")  
{
	output="Ȫ�ݳ���";	
}

if (dir2[1]=="qingzh")  
{
	output="��ظ�ԭ";	
}

if (dir2[1]=="changbaishan" || dir2[1]=="gaoli")  
{
	output="���� ����ɽ";	
}

if (dir2[1]=="annan")  
{
	output="����";	
}

if (dir2[1]=="taiyuan")  
{
	output="̫ԭ";	
}

if (dir2[1]=="hefei")  
{
	output="�Ϸ�";	
}

if (dir2[1]=="jiujiang")  
{
	output="�Ž�";	
}

if (dir2[1]=="baling")  
{
	output="����";	
}

if (dir2[1]=="xinjiang")  
{
	output="�½�";	
}
if (dir2[1]=="dingxiang")  
{
	output="����";	
}
if (dir2[1]=="suiye")  
{
	output="��Ҷ";	
}


if (dir2[1]=="mayi")  
{
	output="���ر߽�";	
}
if (dir2[1]=="xuzhou")  
{
	output="���ݳ�";	
}
if (dir2[1]=="jinan")  
{
	output="���ϳ�";	
}
if (dir2[1]=="guizhou")  
{
	output="������";	
}

if (dir2[1]=="nanchang")  
{
	output="�ϲ���";	
}


if (dir2[1]=="changsha")  
{
	output="��ɳ��";	
}


if (dir2[1]=="zhongzhou")  
{
	output="���ݳ�";	
}

if (dir2[1]=="xizang" || dir2[1]=="zangbei")  
{
	output="���ػ�ر�";	
}

if (dir2[1]=="cloud" )  
{
	output="���������";	
}

if (dir2[1]=="xueting" )  
{
	output="����ѩͤ��";	
}

if (dir2[1]=="ny" )  
{
	output="������Զ��";	
}

if (dir2[1]=="fengtian" )  
{
	output="����ʢ����";	
}

if (dir2[1]=="yanmen" )  
{
	output="���Ź�";	
}

if (dir2[1]=="linzhi" )  
{
	output="������֥����";	
}

if (dir2[1]=="datong" )  
{
	output="��ͬ��";	
}

if (dir2[1]=="tianshui" )  
{
	output="��ˮ��";	
}

if (dir2[1]=="heifeng" )  
{
	output="�ڷ�կ";	
}

if (dir2[1]=="paiyun" )  
{
	output="����կ";	
}


if (dir2[1]=="yeyangzai" )  
{
	output="Ұ��կ";	
}


if (dir2[1]=="jinghai" )  
{
	output="������";	
}

if (dir2[1]=="zuojiacun" )  
{
	output="��ͤ��";	
}


if (dir2[1]=="houjizhen" )  
{
	output="���";	
}

if (dir2[1]=="huayin" )  
{
	output="ͭɽ��";	
}

if (dir2[1]=="lumaji" )  
{
	output="¹��";	
}


if (dir2[1]=="xiyu/gaochang" || dir2[1]=="xiyu/hami" || dir2[1]=="xiyu")  
{
	output="����߽�";	
}

if (dir2[1]=="xibei/desert" || dir2[1]=="xibei/kongdong" || dir2[1]=="xibei/liangzhou" || dir2[1]=="xibei/xingqing" || dir2[1]=="xibei")  
{
	output="�����߽�";	
}

if (dir2[1]=="zhongyuan/chuzhou" || dir2[1]=="zhongyuan" )  
{
	output="��ԭ����";	
}

if (dir2[1]=="xinan/after_qingcheng" || dir2[1]=="xinan/cunzi" || dir2[1]=="xinan")  
{
	output="�����Ĵ�";	
}

if (dir2[1]=="loulan" )  
{
	output="¥��";	
}

if (dir2[1]=="biancheng" )  
{
	output="�߳�";	
}

if (dir2[1]=="quicksand" )  
{
	output="��ɳĮ";	
}

if (dir2[1]=="tieflag/qianfo" || dir2[1]=="tieflag" || dir2[1]=="tieflag/palace" || dir2[1]=="tieflag/bat" || dir2[1]=="tieflag/chuenyu")  
{
	output="��������";	
}

/*if (sizeof(dir2)>=2)
{
if (dir2[2]=="fy" || dir2[2]=="fycycle")  
{
	output="���Ƴ�";	
}
}*/

if (dir2[1]=="taiping" )  
{
	output="̫ƽ��";	
}

if (dir2[1]=="eren/eren2" || dir2[1]=="eren" )  
{
	output="���˹�";	
}
if (dir2[1]=="welcome" )  
{
	output="�Ŵ�";	
}
if (dir2[1]=="qujing"  )  
{
	output="�������";	
}
//output=dir2[1]+dir2[2];
return output;
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

