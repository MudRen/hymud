// look.c
// colored by ReyGod in 1/10/1997 ----- I love colorful world :)
// ����6/16 ��ǰ�����ֺ�(find)��inventory.c�еļ��������ĳ�����
// ���look.c�м���Ҫ��һ���ݣ��ش˸�лfind��������

#include <room.h>
#include <ansi.h>
#include <combat.h>
//#define TIME_TICK1 (time()*60-900000000)
#define TIME_TICK1 (time()*60)
//#define TIME_TICK1 ((time()-900000000)*24)
//#define TIME_TICK1 (time()*60-890000000)

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
        int i, j, k, l;
        object *inv;
        mapping exits,*data;
        string str, *dirs,str2,str1;
        mixed *cmds;
        k = 0;
	data = allocate(3000);

        if( !env ) {
                write("������ܻ����ɵ�һƬ��ʲôҲû�С�\n");
                return 1;
        }
// ������ɫ
       switch (NATURE_D->outdoor_room_outcolor())
        {
              case "BLK":
        str = sprintf( BLK + "��"+ "%s"+"��"+ NOR + " - %s\n    %s" + BLK + "%s" + NOR,
                env->query("short"),
                wizardp(me)? file_name(env): "",
                env->query("long"),
                env->query("outdoors")? NATURE_D->outdoor_room_description():"");
                   break;
              case "RED":
        str = sprintf( RED + "��"+ "%s"+"��"+ NOR + " - %s\n    %s" + RED + "%s" + NOR,
                env->query("short"),
                wizardp(me)? file_name(env): "",
                env->query("long"),
                env->query("outdoors")? NATURE_D->outdoor_room_description():"");
                   break;
              case "HIR":
        str = sprintf( HIR + "��"+ "%s"+"��"+ NOR + " - %s\n    %s" + HIR + "%s" + NOR,
                env->query("short"),
                wizardp(me)? file_name(env): "",
                env->query("long"),
                env->query("outdoors")? NATURE_D->outdoor_room_description():"");
                   break;
              case "GRN":
        str = sprintf( GRN + "��"+ "%s"+"��"+ NOR + " - %s\n    %s" + GRN + "%s" + NOR,
                env->query("short"),
                wizardp(me)? file_name(env): "",
                env->query("long"),
                env->query("outdoors")? NATURE_D->outdoor_room_description():"");
                   break;
              case "HIG":
        str = sprintf( HIG + "��"+ "%s"+"��"+ NOR + " - %s\n    %s" + HIG + "%s" + NOR,
                env->query("short"),
                wizardp(me)? file_name(env): "",
                env->query("long"),
                env->query("outdoors")? NATURE_D->outdoor_room_description():"");
                   break;
              case "YEL":
        str = sprintf( YEL + "��"+ "%s"+"��"+ NOR + " - %s\n    %s" + YEL + "%s" + NOR,
                env->query("short"),
                wizardp(me)? file_name(env): "",
                env->query("long"),
                env->query("outdoors")? NATURE_D->outdoor_room_description():"");
                   break;
              case "HIY":
        str = sprintf( HIY + "��"+ "%s"+"��"+ NOR + " - %s\n    %s" + HIY + "%s" + NOR,
                env->query("short"),
                wizardp(me)? file_name(env): "",
                env->query("long"),
                env->query("outdoors")? NATURE_D->outdoor_room_description():"");
                   break;
              case "BLU":
        str = sprintf( BLU + "��"+ "%s"+"��"+ NOR + " - %s\n    %s" + BLU + "%s" + NOR,
                env->query("short"),
                wizardp(me)? file_name(env): "",
                env->query("long"),
                env->query("outdoors")? NATURE_D->outdoor_room_description():"");
                   break;
              case "HIB":
        str = sprintf( HIB + "��"+ "%s"+"��"+ NOR + " - %s\n    %s" + HIB + "%s" + NOR,
                env->query("short"),
                wizardp(me)? file_name(env): "",
                env->query("long"),
                env->query("outdoors")? NATURE_D->outdoor_room_description():"");
                   break;
              case "MAG":
        str = sprintf( MAG + "��"+ "%s"+"��"+ NOR + " - %s\n    %s" + MAG + "%s" + NOR,
                env->query("short"),
                wizardp(me)? file_name(env): "",
                env->query("long"),
                env->query("outdoors")? NATURE_D->outdoor_room_description():"");
                   break;
              case "HIM":
        str = sprintf( HIM + "��"+ "%s"+"��"+ NOR + " - %s\n    %s" + HIM + "%s" + NOR,
                env->query("short"),
                wizardp(me)? file_name(env): "",
                env->query("long"),
                env->query("outdoors")? NATURE_D->outdoor_room_description():"");
                   break;
              case "CYN":
        str = sprintf( CYN + "��"+ "%s"+"��"+ NOR + " - %s\n    %s" + CYN + "%s" + NOR,
                env->query("short"),
                wizardp(me)? file_name(env): "",
                env->query("long"),
                env->query("outdoors")? NATURE_D->outdoor_room_description():"");
                   break;
              case "HIC":
        str = sprintf( HIC + "��"+ "%s"+"��"+ NOR + " - %s\n    %s" + HIC + "%s" + NOR,
                env->query("short"),
                wizardp(me)? file_name(env): "",
                env->query("long"),
                env->query("outdoors")? NATURE_D->outdoor_room_description():"");
                   break;
              case "WHT":
        str = sprintf( WHT + "��"+ "%s"+"��"+ NOR + " - %s\n    %s" + WHT + "%s" + NOR,
                env->query("short"),
                wizardp(me)? file_name(env): "",
                env->query("long"),
                env->query("outdoors")? NATURE_D->outdoor_room_description():"");
                   break;
              case "HIW":
        str = sprintf( HIW + "��"+ "%s"+"��"+ NOR + " - %s\n    %s" + HIW + "%s" + NOR,
                env->query("short"),
                wizardp(me)? file_name(env): "",
                env->query("long"),
                env->query("outdoors")? NATURE_D->outdoor_room_description():"");
                   break;
              default:
        str = sprintf( HIC + "��"+ "%s"+"��"+ NOR + " - %s\n    %s" + HIG + "%s" + NOR,
                env->query("short"),
                wizardp(me)? file_name(env): "",
                env->query("long"),
                env->query("outdoors")? NATURE_D->outdoor_room_description():"");
                   break;
	}
// �������˽���
/*    if (!objectp(present("fire", me))  && environment(me)->query("outdoors") 
    && !wizardp(this_player()) 
    &&   ((strsrch(CHINESE_D->chinese_date(TIME_TICK1), "��ʱ") >= 0) ||
         (strsrch(CHINESE_D->chinese_date(TIME_TICK1), "��ʱ") >= 0) ||
         (strsrch(CHINESE_D->chinese_date(TIME_TICK1), "��ʱ") >= 0) ||
         (strsrch(CHINESE_D->chinese_date(TIME_TICK1), "��ʱ") >= 0))
     )
    str = sprintf( "%s"+NOR+BLU+"\n����  ҹ���ˣ�����Ȼ�������۾���ϸ�ۿ����ɻ��ǿ��������Χ�����\n"+
			"һ�ж���ҹɫ�����֣������µĵ�·��ģ��������...\n"+NOR+"",
        env->query("short"));
*/
        if( mapp(exits = env->query("exits")) ) {
                dirs = keys(exits);
                for(i=0; i<sizeof(dirs); i++)
                        if( (int)env->query_door(dirs[i], "status") & DOOR_CLOSED )
                                dirs[i] = 0;
                dirs -= ({ 0 });
/*                if ( env->query("outdoors") &&
                    !present("fire", this_player()) &&
                    !wizardp(this_player()) &&
                    ((strsrch(CHINESE_D->chinese_date(TIME_TICK1), "��ʱ") >= 0) ||
                     (strsrch(CHINESE_D->chinese_date(TIME_TICK1), "��ʱ") >= 0) ||
                     (strsrch(CHINESE_D->chinese_date(TIME_TICK1), "��ʱ") >= 0) ||
                     (strsrch(CHINESE_D->chinese_date(TIME_TICK1), "��ʱ") >= 0)))
                        str += BLU + "    ��ɫ̫���ˣ��㿴�������Եĳ�·��\n"NOR;
                else  */
				//	dirs -= ({ 0 });
		if( sizeof(dirs)==0 )
                        str += HIR + "    ����û���κ����Եĳ�·��\n"NOR;
		else if( sizeof(dirs)==1 )
                        str += YEL + "    �������Ե�"+ HIC +"�����ڡ�"+ HIG +"��" + BOLD + dirs[0] + NOR + "��\n";
		else
                        str += sprintf(  HIG + "    �������Ե�"+ HIC +"�����ڡ�"+ HIG +"��" + BOLD + "%s" + NOR + " " + HIG + "��  " + BOLD + "%s" + NOR + "��\n",
                                implode(dirs[0..sizeof(dirs)-2], "��"), dirs[sizeof(dirs)-1]);
        }
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
/*               if ( env->query("outdoors") &&
                    !present("fire", this_player()) 
                     && !wizardp(this_player())                     
                    && ((strsrch(CHINESE_D->chinese_date(TIME_TICK1), "��ʱ") >= 0) ||
                     (strsrch(CHINESE_D->chinese_date(TIME_TICK1), "��ʱ") >= 0) ||
                     (strsrch(CHINESE_D->chinese_date(TIME_TICK1), "��ʱ") >= 0) ||
                     (strsrch(CHINESE_D->chinese_date(TIME_TICK1), "��ʱ") >= 0)))
				str = sprintf("%s", str);
else*/				str = sprintf("%s%s%s\n", str,  (data[l]["num"]==1)? "  ":"  "+ chinese_number(data[l]["num"])+data[l]["unit"], data[l]["id"]);
		}
if (me->query_temp("xmud"))write ("��ͼ:\n");
if (me->query("env/showmap")) realtime_map(me,env);              
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
if (obj->query("makeritem")==1 || obj->query("systemmake")==1 )
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

int help (object me)
{
        write(@HELP
ָ���ʽ: look [<��Ʒ>|<����>|<����>]

���ָ������鿴�����ڵĻ�����ĳ����Ʒ��������Ƿ���

HELP
);
        return 1;
}

