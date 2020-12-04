// Room: /city/guangchang.c
// YZC 1995/12/04 

inherit ROOM;

#include <ansi.h>


#define TIME_TICK1 (time()*60)

string *default_dirs=({
"south",
"north",
"west",
"east",
});

mapping default_dirs2 = ([
	"north":	"����",
	"south":	"�Ϸ�",
	"east":		"����",
	"west":		"����",
	"out":		"����",
]);
string tname="migong48";
string oname="/d/changsha/eroad3";
string mnpc="/p/migong/migong/npc/npc48";
string mboss="/p/migong/migong/npc/boss48";
string mbox="/clone/box/gbox";
int st=random(4);

int setn(int j)
{
	if (j==0) j=1;
	else if (j==1) j=0;
	else if (j==2) j=3;
  else if (j==3) j=2;	
if (j==1  && random(3)==0) j=2;
else if (j==1 && random(3)==0) j=0;
else if (j==1) j=3;
else if (j==2 && random(3)==0) j=3;
else if (j==2 && random(3)==0) j=1;
else if (j==2) j=0;
else if (j==3 && random(3)==0) j=0;
else if (j==3 && random(3)==0) j=1;
else if (j==3) j=2;
else if (j==0 && random(3)==0) j=1;
else if (j==0 && random(3)==0) j=2;
else if (j==0) j=3;
	return j;
}


int setn2(int j)
{
	if (j==0) j=1;
	else if (j==1) j=0;
	else if (j==2) j=3;
  else if (j==3) j=2;

	return j;
}


void create ()
{
	//string tname,oname;
	int st2,j,i,k;
	if (st==0) st2=1;
	else if (st==1) st2=2;
	else if (st==2) st2=3;
	else if (st==3) st2=2;


  set ("short", "��´ɽ");
  set ("long", @LONG
��´ɽ����������Ļ��ľ�������ʤ�ż��ڶ࣬�����͵�Ϊһ�壬��ʷʥ���鲼��ֲ����Դ�ḻ��
LONG );
 //set("maze",1);
set("mglvl",570);
  set("hxsdmigong",1);
set("no_drop1",1);
  set("box1",random(10)+1);
  set("box2",random(10)+11);
  set("box3",random(10)+21);
  set("box4",random(10)+31);
  set("box5",random(10)+41);
  set("mgnpc",random(3));
  set("mgboss","1");
  set("mgstart","1");
  set("0",st);
  set("0b","out");
  j=st;
  
//                for(k=1; k<=sizeof(50); k++)  
//{
  i=setn2(j);
  j=setn(j);
  set("1",j);
  set("1b",default_dirs[i]);
  
  i=setn2(j);
  j=setn(j);
  set("2",j);
  set("2b",default_dirs[i]);
  i=setn2(j);
  j=setn(j);
  set("3",j);
  set("3b",default_dirs[i]);

 i=setn2(j);
  j=setn(j);
  set("4",j);
  set("4b",default_dirs[i]);
  i=setn2(j);
  j=setn(j);
  set("5",j);
  set("5b",default_dirs[i]);
  i=setn2(j);
  j=setn(j);
  set("6",j);
  set("6b",default_dirs[i]);    
  i=setn2(j);
  j=setn(j);
  set("7",j);
  set("7b",default_dirs[i]);  
  i=setn2(j);
  j=setn(j);
  set("8",j);
  set("8b",default_dirs[i]);  
  i=setn2(j);
  j=setn(j);
  set("9",j);
  set("9b",default_dirs[i]);  
  i=setn2(j);
  j=setn(j);
  set("10",j);
  set("10b",default_dirs[i]);        

 set("11",j);
  set("11b",default_dirs[i]);
  i=setn2(j);
  j=setn(j);
  set("12",j);
  set("12b",default_dirs[i]);
  i=setn2(j);
  j=setn(j);
  set("13",j);
  set("13b",default_dirs[i]);
  i=setn2(j);
  j=setn(j);
  set("14",j);
  set("14b",default_dirs[i]);
  i=setn2(j);
  j=setn(j);
  set("15",j);
  set("15b",default_dirs[i]);
  i=setn2(j);
  j=setn(j);
  set("16",j);
  set("16b",default_dirs[i]);    
  i=setn2(j);
  j=setn(j);
  set("17",j);
  set("17b",default_dirs[i]);  
  i=setn2(j);
  j=setn(j);
  set("18",j);
  set("18b",default_dirs[i]);  
  i=setn2(j);
  j=setn(j);
  set("19",j);
  set("19b",default_dirs[i]);  
  i=setn2(j);
  j=setn(j);
  set("20",j);
  set("20b",default_dirs[i]);     
  
 set("21",j);
  set("21b",default_dirs[i]);
  i=setn2(j);
  j=setn(j);
  set("22",j);
  set("22b",default_dirs[i]);
  i=setn2(j);
  j=setn(j);
  set("23",j);
  set("23b",default_dirs[i]);
  i=setn2(j);
  j=setn(j);
  set("24",j);
  set("24b",default_dirs[i]);
  i=setn2(j);
  j=setn(j);
  set("25",j);
  set("25b",default_dirs[i]);
  i=setn2(j);
  j=setn(j);
  set("26",j);
  set("26b",default_dirs[i]);    
  i=setn2(j);
  j=setn(j);
  set("27",j);
  set("27b",default_dirs[i]);  
  i=setn2(j);
  j=setn(j);
  set("28",j);
  set("28b",default_dirs[i]);  
  i=setn2(j);
  j=setn(j);
  set("29",j);
  set("29b",default_dirs[i]);  
  i=setn2(j);
  j=setn(j);
  set("30",j);
  set("30b",default_dirs[i]);     
  
 set("31",j);
  set("31b",default_dirs[i]);
  i=setn2(j);
  j=setn(j);
  set("32",j);
  set("32b",default_dirs[i]);
  i=setn2(j);
  j=setn(j);
  set("33",j);
  set("33b",default_dirs[i]);
  i=setn2(j);
  j=setn(j);
  set("34",j);
  set("34b",default_dirs[i]);
  i=setn2(j);
  j=setn(j);
  set("35",j);
  set("35b",default_dirs[i]);
  i=setn2(j);
  j=setn(j);
  set("36",j);
  set("36b",default_dirs[i]);    
  i=setn2(j);
  j=setn(j);
  set("37",j);
  set("37b",default_dirs[i]);  
  i=setn2(j);
  j=setn(j);
  set("38",j);
  set("38b",default_dirs[i]);  
  i=setn2(j);
  j=setn(j);
  set("39",j);
  set("39b",default_dirs[i]);  
  i=setn2(j);
  j=setn(j);
  set("40",j);
  set("40b",default_dirs[i]);     
  
 set("41",j);
  set("41b",default_dirs[i]);
  i=setn2(j);
  j=setn(j);
  set("42",j);
  set("42b",default_dirs[i]);
  i=setn2(j);
  j=setn(j);
  set("43",j);
  set("43b",default_dirs[i]);
  i=setn2(j);
  j=setn(j);
  set("44",j);
  set("44b",default_dirs[i]);
  i=setn2(j);
  j=setn(j);
  set("45",j);
  set("45b",default_dirs[i]);
  i=setn2(j);
  j=setn(j);
  set("46",j);
  set("46b",default_dirs[i]);    
  i=setn2(j);
  j=setn(j);
  set("47",j);
  set("47b",default_dirs[i]);  
  i=setn2(j);
  j=setn(j);
  set("48",j);
  set("48b",default_dirs[i]);  
  i=setn2(j);
  j=setn(j);
  set("49",j);
  set("49b",default_dirs[i]);  
  i=setn2(j);
  j=setn(j);
  set("50",j);
  set("50b","out");            
//  }  


set("startr",st2);
  set("exits", ([ 
default_dirs[st] : __DIR__+tname,
  "out" : oname,
	  	
]));

set("tname",tname);
  set("no_sleep_room", 1);
  setup();

}


int look_room(object me, object env)
{
        int i, j, k, l;
        object *inv;
        mapping exits,*data;
        string str, *dirs,str2,str1;
        mixed *cmds;
        string message,modify,strrk;
        k = 0;
	data = allocate(3000);

        if( !env ) {
                write("������ܻ����ɵ�һƬ��ʲôҲû�С�\n");
                return 1;
        }
 str = sprintf( "��"+ "%s"+"��" + " - %s\n    %s"  + "%s",
                env->query("short"),
                wizardp(me)? file_name(env): "",
                env->query("long"),
                env->query("outdoors")? NATURE_D->outdoor_room_description():"");

        if( mapp(exits = env->query("exits")) ) {
                dirs = keys(exits);
                for(i=0; i<sizeof(dirs); i++)
//                        if( (int)env->query_door(dirs[i], "status") & DOOR_CLOSED )
//                                dirs[i] = 0;
                dirs -= ({ 0 });

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
				str = sprintf("%s%s%s\n", str,  (data[l]["num"]==1)? "  ":"  "+ chinese_number(data[l]["num"])+data[l]["unit"], data[l]["id"]);
            }
        write(str);
        
if (me->query_temp("xmud"))
{
 k = 0;
	data = allocate(3000);
	if( !env ) {
		write("������ܻ����ɵ�һƬ��ʲôҲû�С�\n");
		return 1;
	}

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

str="";

}        
        
        return 1;
}

int valid_leave(object me, string dir)
{
object env,fang;
int i,wjxh,j,wjxh2,k,addok;
string dir2,dir3,dir1,dir4,dir5,dir6;
mapping exit;
object *inv;
env = this_object();
wjxh=me->query_temp("migongxh");
if (me->is_fighting())
	{
			if (me->query_temp("xmud")) tell_object(me, "������ս���С�\n");
			return notify_fail("������ս���С�\n");
		}
if (me->is_busy())
		{
			if (me->query_temp("xmud")) tell_object(me, "������æ���С�\n");
			return notify_fail("������æ���С�\n");
		}


if( !mapp(exit = env->query("exits")) || undefinedp(exit[dir]) ) 
					{
			if (me->query_temp("xmud")) tell_object(me, "�������û�г�·��\n");
			return notify_fail("�������û�г�·��\n");
		}


inv = all_inventory(env);
		for (i = 0; i < sizeof(inv); i++) {
 			if ( !userp(inv[i])
			&&  inv[i]->query("mgnpc"))

			{
				if (me->query_temp("xmud")) tell_object(me, "���︽��������û�����ء�\n");
return notify_fail("���︽��������û�����ء�\n");
			}

		}

dir1=env->query("addlj");
dir2=env->query("dellj");
dir4=env->query("addlj");
dir5=env->query("dellj");

addok=2;

//if (wizardp(me)) tell_object(me, "ԭ��" + me->query_temp("migongxh",1) + "��\n");
if (dir1 && dir2 )
{
if (dir==dir1 || !dir1)
 {
addok=1;
me->add_temp("migongxh",1);
//if (wizardp(me)) tell_object(me, "����" + dir1 + "��\n");
}

if (dir==dir2 ||  !dir2 )  {
addok=2;
me->add_temp("migongxh",-1);
//if (wizardp(me)) tell_object(me, "����" + dir2 + "��\n");
}
}	

wjxh2=me->query_temp("migongxh");
if (wizardp(me)) tell_object(me, "����" + wjxh2 + "��\n");

env->set("migongxh",wjxh2);
//env->set("short", "����ɽ"+wjxh2);
if (me->query_temp("migongxh",1)<0) me->set_temp("migongxh",0);
if (me->query_temp("migongxh",1)>50) me->set_temp("migongxh",50);

j=env->query(""+wjxh2+"");
dir6=env->query(""+wjxh2+"b");
k=env->query(""+wjxh+"");
if (dir=="west") dir3="east";
if (dir=="east") dir3="west";
if (dir=="south") dir3="north";
if (dir=="north") dir3="south";

	

/*
if (wizardp(me))
	{
tell_object(me, "����" + dir + "��\n");
tell_object(me, "������" + me->query_temp("migongxh",1) + "��\n");
tell_object(me, "����ȥ·��"+wjxh2+":" + default_dirs[j] + "��\n");
tell_object(me, "������·��" + dir6 + "��\n");

tell_object(me, "�ϴ�·��ȥ" + dir1 + "��\n");
tell_object(me, "�ϴ�·����" + dir2 + "��\n");
}

*/
if (dir=="out")
{
me->set_temp("migongxh",0);
me->delete_temp("migongxh");
me->move(oname);
//tell_object(me, "�ƶ�" + oname + "��\n");
return notify_fail("����"+default_dirs2[dir]+"��ȥ��\n");
}
env->delete("exits");

if (wjxh2==0)
{
me->delete_temp("migongxh");	
env->delete("addlj");
env->delete("dellj");	
env->set("exits/out",oname);
env->set("exits/"+default_dirs[st],__DIR__+tname);
env->set("addlj",default_dirs[st]);
env->set("dellj","out");
}
else
if (wjxh2==50)
{
env->set("exits/out",oname);
env->delete("addlj");
env->delete("dellj");

}
else
{
dir4=default_dirs[j];
dir5=dir6;
env->set("exits/"+dir4,__DIR__+tname);
env->set("exits/"+dir5,__DIR__+tname);
env->set("addlj",dir4);
env->set("dellj",dir5);
if (random(8)==0)
{	
env->set("exits/"+default_dirs[random(3)],__DIR__+tname);
env->set("exits/"+default_dirs[random(3)],__DIR__+tname);
env->set("exits/"+default_dirs[random(3)],__DIR__+tname);
env->set("exits/"+default_dirs[random(3)],__DIR__+tname);
}

}
//if (addok==2) tell_object(me, "���� ��\n");
//if (addok==1) tell_object(me, "���� ��\n");


        inv = all_inventory(env);
		for (i = 0; i < sizeof(inv); i++) {
 			if (inv[i]!=me 
			&&  !userp(inv[i])
			&&  !inv[i]->query("mgnpc")
			&& !living(inv[i])
			
)
			{
inv[i]->move("/clone/misc/void");
destruct(inv[i]);
			}

		}
if (random(50)==0 && (env->query("killbh",1) <=2 || !env->query("killbh"))) 
{
if (me->query_temp("migongxh",1)<=5) me->set_temp("migongxh",1);	
if (me->query_temp("migongxh",1)>=10) me->set_temp("migongxh",(random(10)+1));	
if (me->query_temp("migongxh",1)>=20) me->set_temp("migongxh",(random(10)+10));	
if (me->query_temp("migongxh",1)>=30) me->set_temp("migongxh",(random(10)+20));	
tell_object(me, "ֻ�����ܹ�Ӱ�ζ�������һ�а������������⾰���ƺ������ı䡣\n");
env->add("killbh",1);	
}

if (me->query_temp("migongxh",1)==10 || me->query_temp("migongxh",1)==20  || me->query_temp("migongxh",1)==30  || me->query_temp("migongxh",1)==40  || me->query_temp("migongxh",1)==45 )  
tell_object(me, "���λ����������� �ٷ�֮"+chinese_number((me->query_temp("migongxh",1)*2))+"�ĵط��ˡ�\n");



if (!wizardp(me) && random(5)==0 && (env->query("killdl",1) <=38 || !env->query("killdl")) ) 
{
fang = new(mnpc);
	fang->move(env);	
	fang->kill_ob(me);
	//me->kill_ob(fang);
if (random(2)==0)
{
fang = new(mnpc);
	fang->move(env);	
	fang->kill_ob(me);
//me->kill_ob(fang);
}	
	
if (!me->is_busy()) me->start_busy(2);
env->add("killdl",1);	
	
}

if (me->query_temp("migongxh",1)==env->query("box1") ) 
{
fang = new(mbox);
	fang->move(env);	
env->set("box1",999);	
}

if (me->query_temp("migongxh",1)==env->query("box2") ) 
{
fang = new(mbox);
	fang->move(env);	
env->set("box2",999);	
}

if (me->query_temp("migongxh",1)==env->query("box3") ) 
{
fang = new(mbox);
	fang->move(env);	
env->set("box3",999);	
}

if (me->query_temp("migongxh",1)==env->query("box4") ) 
{
fang = new(mbox);
	fang->move(env);	
env->set("box4",999);	
}

if (me->query_temp("migongxh",1)==env->query("box5") ) 
{
fang = new(mbox);
	fang->move(env);	
env->set("box5",999);	
}

if (me->query_temp("migongxh",1)==50 && !env->query("killbs") ) 
{
fang = new(mboss);
	fang->move(env);	
	fang->kill_ob(me);

env->set("killbs",1);	
	
}

env->set("mgstart",0);
	seteuid(getuid());
	
tell_object(me, "����"+default_dirs2[dir]+"��ȥ��\n");
	look_room(me,env);
	
	return 1;
}