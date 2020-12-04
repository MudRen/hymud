// This program is a part of NITAN MudLIB

#include <ansi.h>
#include <localtime.h>
#include <mudlib.h>
#include <command.h>

inherit F_DBASE;

#define MIN             0
#define HOUR            1
#define WDAY            2
#define MDAY            3
#define MON             4
#define YEAR            5

#define DATA_PATH       "/data/timed.o"
#define MAZE_DOOR1      "/clone/misc/maze_door1"


string  zuji(string str)
{   
string output;
      	if (str=="baituo")  

	output="����ɽ";

if (str=="binghuodao")  

	output="����";

if (str=="city")  

	output="����";

if (str=="city2" || str=="beijing"  || str=="huanggon"  || str=="huanggong" || str=="beihai")  

	output="������";

if (str=="city4" || str=="changan")   

	output="������";

if (str=="dali")  

	output="����";

if (str=="emei")  

	output="��üɽ";

if (str=="foshan")  

	output="��ɽ";

if (str=="gaibang")  

	output="ؤ��";

if (str=="gaochang")  

	output="�߲��Թ�";

if (str=="guanwai")  

	output="����";

if (str=="guiyun")  

	output="����ׯ";

if (str=="gumu")  

	output="��Ĺ��";

if (str=="hangzhou")  

	output="����";

if (str=="heimuya")  

	output="��ľ��";

if (str=="hengshan")  

	output="��ɽ";

if (str=="henshan")  

	output="��ɽ";

if (str=="huanghe")  

	output="�ƺӾ���";

if (str=="huashan")  

	output="��ɽ";

if (str=="jinshe")  

	output="����ɽ��";

if (str=="lingjiu")  

	output="���չ�";

if (str=="lingzhou")  

	output="����";

if (str=="meizhuang")  

	output="÷ׯ";

if (str=="mingjiao")  

	output="����";

if (str=="qingcheng")  

	output="���ɽ";

if (str=="quanzhen")  

	output="ȫ����";

if (str=="quanzhou")  

	output="Ȫ��";

if (str=="shaolin")  

	output="������";

if (str=="shenlong")  

	output="������";

if (str=="songshan")  

	output="��ɽ";

if (str=="suzhou")  

	output="����";

if (str=="taishan")  

	output="̩ɽ";

if (str=="taohua")  

	output="�һ���";

if (str=="tianlongsi")  

	output="������";

if (str=="wanjiegu")  

	output="��ٹ�";

if (str=="wudang")  

	output="�䵱ɽ";

if (str=="xiakedao")  

	output="���͵�";

if (str=="xiangyang")  

	output="������";

if (str=="xiaoyao")  

	output="��ң��";

if (str=="xingxiu")  

	output="���޺�";

if (str=="xueshan")  

	output="ѩɽ��";

if (str=="xuedao")  

	output="��ѩɽ";

if (str=="mr")  

	output="Ľ������";

if (str=="kunlun")  

	output="����ɽ";

if (str=="tiezhang")  

	output="������";

if (str=="huizhu")  

	output="���岿��";

if (str=="yinju")  

	output="һ�ƴ�ʦ��";

if (str=="menggu")  

	output="�ɹŲ�ԭ";

if (str=="qianjin")  

	output="����ǧ��¥";

if (str=="lingshedao")  

	output="���ߵ�";

if (str=="ruzhou")  

	output="���ݳ�";

if (str=="kunming")  

	output="����";

if (str=="jingzhou")  

	output="����";

if (str=="yanjing")  

	output="�ྩ";

if (str=="lanzhou" || str=="lanzhouchen")  

	output="����";

if (str=="jyguan")  

	output="�����Ա�������";

if (str=="changcheng")  

	output="�����Ա�����";

if (str=="fairyland")  

	output="���صĺ�÷ɽׯ";

if (str=="sdxl")  

	output="��ħ�������Ĺ";

if (str=="jqg")  

	output="�����";

if (str=="nio")  

	output="ţ�Ҵ�";

if (str=="feihu")  

	output="��������";

if (str=="wuguan")  

	output="�������";

if (str=="village")  

	output="��ɽ��";

if (str=="taohuacun")  

	output="�һ���";

if (str=="pingan")  

	output="ƽ����";

if (str=="lingxiao")  

	output="������";

if (str=="wudujiao")  

	output="�嶾��";

if (str=="hj")  

	output="��ɽ����ԭ";
if (str=="dali/yuxu")  

	output="���������";
if (str=="dali/wuliang")  

	output="��������ɽ";
if (str=="huanghe/yyd")  

	output="�ƺ�����";
if (str=="kaifeng")  

	output="�����";
if (str=="feitian")  

	output="����������";
if (str=="japan")  

	output="�ձ���";
if (str=="tangmen")  

	output="����";
if (str=="luoyang")  

	output="������";

if (str=="chengdu" || str=="city3")  

	output="�ɶ�";

if (str=="baihuagu")  

	output="�ٻ���";

if (str=="heizhao")  

	output="�ٻ��ȡ�����";

if (str=="jiaxing")  

	output="����";

if (str=="shiliang")  

	output="�¼�ׯ";

if (str=="wuyi")  

	output="����ɽ��";

if (str=="yanping")  

	output="��ƽ��";
	

if (str=="jiangling")  
{
	output="�����";
}

if (str=="yueyang")  
{
	output="������";	
}

if (str=="qilian")  
{
	output="����ɽ";	
}

if (str=="shouxihu")  
{
	output="������";	
}

if (str=="wuxi")  
{
	output="������";	
}

if (str=="yixing")  
{
	output="���˳�";	
}
if (str=="taiwan")  
{
	output="̨�����";	
}
if (str=="nanyang")  
{
	output="��������";	
}
if (str=="nanshaolin")  
{
	output="�����ֵ���";	
}

if (str=="cangzhou")  
{
	output="���ݵ���";	
}

if (str=="tanggu")  
{
	output="�����ǵ���";	
}

if (str=="yunhe")  
{
	output="�������˺�";	
}

if (str=="hainan")  
{
	output="���ϵ�";	
}

if (str=="jindezheng")  
{
	output="������";	
}

if (str=="yandang")  
{
	output="�㵴ɽ";	
}

if (str=="jinling")  
{
	output="�����";	
}

if (str=="sandboy")  
{
	output="����ũ��";	
}

if (str=="huangshan")  
{
	output="��ɽ";	
}

if (str=="yubifeng")  
{
	output="��ʷ�";	
}

if (str=="quanzhouchen")  
{
	output="Ȫ�ݳ���";	
}

if (str=="qingzh")  
{
	output="��ظ�ԭ";	
}

if (str=="changbaishan" || str=="gaoli")  
{
	output="���� ����ɽ";	
}

if (str=="annan")  
{
	output="���ϸ���";	
}

if (str=="taiyuan")  
{
	output="̫ԭ����";	
}

if (str=="hefei")  
{
	output="�Ϸʸ���";	
}

if (str=="jiujiang")  
{
	output="�Ž�����";	
}

if (str=="baling")  
{
	output="���긽��";	
}

if (str=="xinjiang")  
{
	output="�½�����";	
}
if (str=="dingxiang")  
{
	output="���帽��";	
}
if (str=="suiye")  
{
	output="��Ҷ����";	
}


if (str=="mayi")  
{
	output="���ر߽�����";	
}
if (str=="xuzhou")  
{
	output="���ݳǸ���";	
}
if (str=="jinan")  
{
	output="���ϳǸ���";	
}
if (str=="guizhou")  
{
	output="�����Ǹ���";	
}

if (str=="nanchang")  
{
	output="�ϲ��Ǹ���";	
}


if (str=="changsha")  
{
	output="��ɳ�Ǹ���";	
}


if (str=="zhongzhou")  
{
	output="���ݳǸ���";	
}

if (str=="xizang" || str=="zangbei")  
{
	output="���ػ�ر�����";	
}

return output;
}

object get_object(string name) 
{ 
            object ob; 
            
            if (ob = find_object(name)) 
                    return ob; 
                     
           sscanf(name, "%s#%*s", name);  
            return load_object(name); 
} 




int gametime;
static int realtime;
static int tick;
static mapping event = allocate_mapping(0);
static int *real_time = allocate(6);
static int *game_time = allocate(6);


static  mapping *migongl = ({
(["ename":"vrm00","cname":"ԭʼɭ��","where": "/d/kunming/nanmen","rk": "/p/migong/boss/vrm_0000/entry"  ]),
(["ename":"vrm01","cname":"�����Թ�","where": "/d/xiakedao/haitan","rk": "/p/migong/boss/vrm_00011/entry"  ]),
(["ename":"vrm02","cname":"��֮��ͷ","where": "/d/guanwai/tianchi1","rk": "/p/migong/boss/vrm_00021/entry"  ]),
(["ename":"vrm03","cname":"��֮����","where": "/d/xueshan/hubian3","rk": "/p/migong/boss/vrm_00031/entry"  ]),
(["ename":"vrm04","cname":"����֮԰","where": "/d/taiwan/riyuetan","rk": "/p/migong/boss/vrm_00041/entry"  ]),
(["ename":"vrm05","cname":"����֮��","where": "/d/qingcheng/path1","rk": "/p/migong/boss/vrm_00051/entry"  ]),
(["ename":"vrm06","cname":"����ɭ��","where": "/d/hengshan/daziling","rk": "/p/migong/boss/vrm_00061/entry"  ]),
(["ename":"vrm07","cname":"�ٻ�֮��","where": "/d/xiangyang/caodi5","rk": "/p/migong/boss/vrm_00071/entry"  ]),						
(["ename":"vrm08","cname":"����ɽ��","where": "/d/emei/yunufeng","rk": "/p/migong/boss/vrm_00081/entry"  ]),
(["ename":"vrm09","cname":"��������","where": "/d/songshan/fengchantai","rk": "/p/migong/boss/vrm_00091/entry"  ]),
(["ename":"vrm10","cname":"�޵��ܶ�","where": "/d/dali/yuxiashan","rk": "/p/migong/boss/vrm_00101/entry"  ]),
(["ename":"vrm11","cname":"����ħ��","where": "/d/xizang/timetree","rk": "/p/migong/boss/vrm_00111/entry"  ]),
(["ename":"vrm12","cname":"ɱ��֮ׯ","where": "/d/beijing/tian_anm","rk": "/p/migong/boss/vrm_0012/entry"  ]),
(["ename":"vrm13","cname":"���ƳǱ�","where": "/d/huashan/chaoyang","rk": "/p/migong/boss/vrm_0013/entry"  ]),
(["ename":"vrm14","cname":"����֮��","where": "/d/henshan/wangritai","rk": "/p/migong/boss/vrm_0014/entry"  ]),
(["ename":"vrm15","cname":"��żɽׯ","where": "/d/suzhou/canlangting","rk": "/p/migong/boss/vrm_0015/entry"  ]),				
(["ename":"vrm16","cname":"��֮����","where": "/d/xingxiu/shashan","rk": "/p/migong/boss/vrm16/maze/entry"  ]),
(["ename":"vrm17","cname":"ˮû����","where": "/d/japan/zhanbu","rk": "/p/migong/boss/vrm17/maze/entry"  ]),
(["ename":"vrm18","cname":"�����Թ�","where": "/d/huanghe/hetao","rk": "/p/migong/boss/vrm18/maze/entry"  ]),
(["ename":"vrm19","cname":"�ɴ��ż�","where": "/d/xizang/shanyao","rk": "/p/migong/boss/vrm19/maze/entry"  ]),	
(["ename":"vrm20","cname":"������Ĺ","where": "/d/xinjiang/huoyan","rk": "/p/migong/boss/vrm20/maze/entry"  ]),	
(["ename":"vrm21","cname":"���񶴿�","where": "/d/zangbei/hellvalley3","rk": "/p/migong/boss/vrm21/maze/entry"  ]),	
(["ename":"vrm22","cname":"���񹬵�","where": "/d/huanggong/taihedian","rk": "/p/migong/boss/vrm22/maze/entry"  ]),	
});


void auto_relaim()
{
        int i;
//        if (i = reclaim_objects())
//                CHANNEL_D->do_channel( this_object(), "sys",
//                        sprintf("ϵͳ�Զ���� %d ��������", i));
}

void game_new_year()
{
        shout( WHT "\n" + CHINESE_MUD_NAME + CHINESE_D->chinese_number(game_time[YEAR]) + "�������������������ڣ�����\n" NOR);
}

void real_new_year()
{
        shout( WHT"\n��Ԫ" HIW+CHINESE_D->chinese_number(real_time[YEAR])+WHT"�������������������ڣ�����\n"NOR);
        shout( WHT"\n��Ԫ" HIW+CHINESE_D->chinese_number(real_time[YEAR])+WHT"�������������������ڣ�����\n"NOR);
        shout( WHT"\n��Ԫ" HIW+CHINESE_D->chinese_number(real_time[YEAR])+WHT"�������������������ڣ�����\n"NOR);
}

void broadcast_message()
{
        shout(HIW "��ϵͳ��ʾ�������Ա���ܸ���Ļ�Ա����(help member)��������鿴�����ļ�������\n" NOR);
        shout(HIW "��ϵͳ��ʾ��Ŀǰ��Ϸ��ɾ���ڲ⣬�������̳����������ע����ϷID��\n"
              HIW "            �����������Ͽɿɻ�÷��Ʊ� http://www.nbyingqi.com.cn\n" NOR);
}

void double_reward_start()
{
        //shout(BEEP BLINK HIR"����Աͨ�桿���ڵ�ʱ��Ϊ 20 �㣬ϵͳ���Ż�Ա˫������ʱ�俪ʼ������\n"NOR);
}

void double_reward_end()
{
        //shout(BEEP BLINK HIR"����Աͨ�桿���ڵ�ʱ��Ϊ 24 �㣬ϵͳ���Ż�Ա˫������ʱ�����������\n"NOR);
}





void create_vrm_entry(string arg)
{
        object room, maze_door;
        string filename;
        string rooms;
        string *dir2;
        int i;
        i=random(sizeof(migongl));
//i=11;

if (random(2)==0) i=random(2);
else if (random(3)==0) i=2+random(2);
else if (random(4)==0) i=4+random(2);
else if (random(5)==0) i=6+random(2);
else if (random(6)==0) i=8+random(2);
else if (random(7)==0) i=10+random(2);
//else if (random(8)==0) i=15+random(2);

if (arg=="vrm00")
{
i=random(4);
}

if (arg=="vrm01")
{
i=4+random(4);
}

if (arg=="vrm02")
{
i=8+random(4);
}

if (arg=="vrm04")
{
i=12+random(4);
}

if (arg=="vrm05")
{
i=16+random(4);
}

if (arg=="vrm06")
{
i=20+random(3);
}

arg=migongl[i]["ename"];
                filename = migongl[i]["where"]; 
                room = get_object(filename);          
                maze_door = new(MAZE_DOOR1);
                maze_door->set("maze_entry", migongl[i]["rk"] );
                maze_door->set("maze_name", migongl[i]["cname"] );
                maze_door->move(room);

dir2=explode(base_name(room),"/");
rooms=zuji(dir2[1]);
log_file("log", ctime(time())+" �����Թ���" + arg +"\n", 1);        
        
        message("vision", HIG "��" HIR "��������" HIG "��" HIW +
                room->query("short") + HIW "(" + rooms + 
                ")һ��������" + migongl[i]["cname"] + HIW "��\n" NOR, users());
        
        SCHEDULE_D->set_event(3080, 0, this_object(), "close_vrm_entry", i,arg, room, maze_door);
}

void close_vrm_entry(int i,string arg, object room, object maze_door)
{
        string rooms;
string *dir2; 
        if ( !room || !maze_door ) return;
        
        destruct(maze_door);
    dir2=explode(base_name(room),"/");
rooms=zuji(dir2[1]);
        message("vision", HIG"��" HIR"��������" HIG"��" HIW +
                room->query("short") + HIW "(" + rooms+ ")һ�����ֵ�" + 
                migongl[i]["cname"] + HIW "��ʧ�ˡ�\n" NOR, users());
}

// ��Ϸʱ��Ĺ����ų�
static mixed  game_crontab = ({
//"min hour wday mday mon year" : ({ function })
"0 0 * 0 0 *"           , (: game_new_year :),                  "ÿ�귢һ�κ��",
});

// ��ʵʱ��Ĺ����ų�
static mixed  real_crontab = ({
"* * * * * *"           , (: SCHEDULE_D->start_events() :),     "ÿ���Ӽ���ų��������",
"10 */1 * * * *"         , (: create_vrm_entry("vrm04") :),  "ÿ 1 ��Сʱˢ��һ��",
"25 */2 * * * *"         , (: create_vrm_entry("vrm00") :),  "ÿ 2 ��Сʱˢ��һ��",
"35 */3 * * * *"         , (: create_vrm_entry("vrm01") :),  "ÿ 3 ��Сʱˢ��һ��",
"45 */4 * * * *"         , (: create_vrm_entry("vrm02") :),  "ÿ 4 ��Сʱˢ��һ��",
"55 */4 * * * *"         , (: create_vrm_entry("vrm05") :),  "ÿ 4 ��Сʱˢ��һ��",
"58 */6 * * * *"         , (: create_vrm_entry("vrm06") :),  "ÿ 6 ��Сʱˢ��һ��",
});

// ��ȡ�� call_out ֮����
void add_event(function fevent, int delay_time)
{
        if( !sizeof(event) || !event[fevent] )
                event = ([ fevent : delay_time ]);
        else
                event[fevent] = delay_time;
}

// ִ���¼�
void exec_event(function fevent)
{
        if( objectp(function_owner(fevent)) )
                evaluate(fevent);

        map_delete(event, fevent);
}

string replace_ctime(int t)
{
        string month, ctime = ctime(t);

        switch(ctime[4..6])
        {
                case "Jan"      :       month = "01";break;
                case "Feb"      :       month = "02";break;
                case "Mar"      :       month = "03";break;
                case "Apr"      :       month = "04";break;
                case "May"      :       month = "05";break;
                case "Jun"      :       month = "06";break;
                case "Jul"      :       month = "07";break;
                case "Aug"      :       month = "08";break;
                case "Sep"      :       month = "09";break;
                case "Oct"      :       month = "10";break;
                case "Nov"      :       month = "11";break;
                case "Dec"      :       month = "12";break;
        }

        return sprintf("%s/%s/%s %s", month, (ctime[8]==' '?"0"+ctime[9..9]:ctime[8..9]), ctime[<4..<1], ctime[11..15]);
}

string season_period(int m)
{
        switch(m)
        {
                case 2..4:      return "��";
                case 5..7:      return "��";
                case 8..10:     return "��";
                case 11:        return "��";
                case 0..1:      return "��";
                default:        return 0;
        }
}

string week_period(int w)
{
        switch(w)
        {
                case 0:         return "��";
                case 1:         return "һ";
                case 2:         return "��";
                case 3:         return "��";
                case 4:         return "��";
                case 5:         return "��";
                case 6:         return "��";
                default:        return 0;
        }
}

string hour_period(int h)
{
        switch(h)
        {
                case 0..5:      return "�賿";
                case 6..11:     return "����";
                case 12:        return "����";
                case 13..18:    return "����";
                case 19..23:    return "����";
                default:        return 0;
        }
}

/* �ش�ʱ������ ({ �� ʱ �� �� �� �� }) */
int *query_gametime_array()
{
        return game_time;
}

int *query_realtime_array()
{
        return real_time;
}

/* �ش���λʱ���ʾ ���� 3:39 */
string gametime_digital_clock()
{
        int h = game_time[HOUR];
        int m = game_time[MIN];

        return hour_period(h)+" "+(h==12 || (h%=12)>9?""+h:" "+h)+":"+(m>9?""+m:"0"+m);
}
string realtime_digital_clock()
{
        int h = real_time[HOUR];
        int m = real_time[MIN];

        return hour_period(h)+" "+(h==12 || (h%=12)>9?""+h:" "+h)+":"+(m>9?""+m:"0"+m);
}

string time_description(string title, int *t)
{
        return sprintf( NOR WHT+title+NOR"%s�꣬%s��%s��%s������%s��%s%s��%s��"NOR
            ,t[YEAR]==1?"Ԫ":CHINESE_D->chinese_number(t[YEAR])
            ,season_period(t[MON])
            ,!t[MON]?"Ԫ":CHINESE_D->chinese_number(t[MON]+1)
            ,CHINESE_D->chinese_number(t[MDAY]+1)
            ,week_period(t[WDAY])
            ,hour_period(t[HOUR])
            ,CHINESE_D->chinese_number(t[HOUR] > 12 ? t[HOUR]%12 : t[HOUR])
            ,CHINESE_D->chinese_number(t[MIN])
        );
}

string game_time_description()
{
        return time_description(CHINESE_MUD_NAME, game_time);
}

string real_time_description()
{
        return time_description("��Ԫ", real_time);
}

int query_game_time()
{
        return gametime*60;
}

int query_real_time()
{
        return realtime;
}

int *analyse_time(int t)
{
        int *ret = allocate(6);
        string ctime;

        ctime = ctime(t);

        sscanf(ctime,"%*s %*s %d %d:%d:%*d %d",ret[MDAY], ret[HOUR], ret[MIN], ret[YEAR]);

        switch(ctime[0..2])
        {
                case "Sun": ret[WDAY] = 0; break;
                case "Mon": ret[WDAY] = 1; break;
                case "Tue": ret[WDAY] = 2; break;
                case "Wed": ret[WDAY] = 3; break;
                case "Thu": ret[WDAY] = 4; break;
                case "Fri": ret[WDAY] = 5; break;
                case "Sat": ret[WDAY] = 6; break;
                default   : return 0;
        }

        switch(ctime[4..6])
        {
                case "Jan": ret[MON] = 0; break;
                case "Feb": ret[MON] = 1; break;
                case "Mar": ret[MON] = 2; break;
                case "Apr": ret[MON] = 3; break;
                case "May": ret[MON] = 4; break;
                case "Jun": ret[MON] = 5; break;
                case "Jul": ret[MON] = 6; break;
                case "Aug": ret[MON] = 7; break;
                case "Sep": ret[MON] = 8; break;
                case "Oct": ret[MON] = 9; break;
                case "Nov": ret[MON] = 10; break;
                case "Dec": ret[MON] = 11; break;
                default   : return 0;
        }
        ret[MDAY] -= 1;
        return ret;
}

void process_crontab(mixed * crontab, int *timearray)
{
        int i, j, row, divider, fit, timecost, crontabsize;
        string s, script, note, *timescript;
        function fp;

        crontabsize = sizeof(crontab);

        for(row=0;row<crontabsize;row+=3)
        {
                reset_eval_cost();
                script = crontab[row];
                fp = crontab[row+1];
                note = crontab[row+2];

                timescript = allocate(6);

                // %s%*(( |\t)+) ����˼�� %s(�ո� or \t ����)���� + ��������һ��һ�����Ϸ��ϵĵ�Ԫ
                if( sscanf(script, "%s%*(( |\t)+)%s%*(( |\t)+)%s%*(( |\t)+)%s%*(( |\t)+)%s%*(( |\t)+)%s",
                        timescript[0],
                        timescript[1],
                        timescript[2],
                        timescript[3],
                        timescript[4],
                        timescript[5]) != 11 ) continue;

                for( i=0;i<6;i++ )
                {
                        fit = 0;

                        foreach(s in explode(timescript[i], ","))
                        {
                                j = to_int(s);

                                // ��ͬ��mudos��undefinedp�������ص�ֵ������
                                if( s == "*" || (sscanf(s, "*/%d", divider) && !(timearray[i]%divider)) )
                                {
                                        fit = 1;
                                        break;
                                }
                                else if( !undefinedp(j) )
                                {
                                        if( j == timearray[i] )
                                        {
                                                fit = 1;
                                                break;
                                        }
                                }
                        }

                        if( !fit ) break;
                }

                if( !fit )
                        continue;

                timecost = time_expression {
                        catch(evaluate(fp));
                };

                if( timecost > 1000000 )
                        CHANNEL_D->do_channel(this_object(), "sys",
                                sprintf("TIME_D: crontab '%s'(%.6f sec) %s", script, timecost/1000000., note));

        }
}

// ��������ÿ��ִ�к�ʽ
void process_per_second()
{

}

void reset_gametime()
{
        gametime = -20000000;
}

/* ��Ϸʱ��ÿһ����(��ʵ��ʱ��ÿ2.5��)ִ��һ�� process_gametime */
void process_gametime()
{
        game_time = analyse_time(++gametime * 60);
        game_time[YEAR] -= 1970;

        process_crontab(game_crontab, game_time);
}

/* ��ʵʱ��ÿһ����ִ��һ�� process_realtime */
void process_realtime()
{
        mixed * localtime = localtime(realtime);

        real_time = ({
                localtime[LT_MIN],
                localtime[LT_HOUR],
                localtime[LT_WDAY],
                localtime[LT_MDAY]-1,
                localtime[LT_MON],
                localtime[LT_YEAR] });
        
        // ÿ��ִ�к�ʽ
        process_per_second();

        if( !localtime[LT_SEC] )
                process_crontab(real_crontab, real_time);
}

// ÿ 1 ������һ��
// ʵ��һ�������Ϸһ��

void heart_beat()
{
        realtime = time();

        // ִ�� event ����
        if( sizeof(event) )
        foreach( function fevent, int delay_time in event )
                if( !--event[fevent] )
                        exec_event(fevent);

        // ÿ 2 ���൱����Ϸһ����, time ÿ���� 1 ������Ϸһ����
        if( !(++tick % 2) )
                process_gametime();

        process_realtime();
}

void create()
{
        seteuid(ROOT_UID);
        set("channel_id", "ʱ�侫��");
        write("ʱ�侫���Ѿ�������\n");
        if( !restore_object(DATA_PATH) )
                save_object(DATA_PATH);

        game_time = allocate(6);
        real_time = allocate(6);
        event = allocate_mapping(0);

        process_gametime();

        //create_vrm_entry("vrm04");



        set_heart_beat(1);
}

int remove()
{
        return save_object(DATA_PATH);
}

string query_name()
{
        return "ʱ��ϵͳ(TIME_D)";
}




