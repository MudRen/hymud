// map.c
#define MaxX 15
#define MaxY 20
#define MinX 7
#define MinY 10

inherit F_CLEAN_UP;


#include "ansi.h"
#include "/doc/help.h"
static int X,Y;
static mixed m;
static string *rfile;
static mapping *data;
int draw_room(int,int,object);
int main2(object me);
void set_room(int,int,object);
void set_x_y(int,int,int);

// ת����ɫ
string clean_color2(string arg)
{
    if(!arg)     return "";
    arg = replace_string(arg, BLK, "");
    arg = replace_string(arg, RED, "");
    arg = replace_string(arg, GRN, "");
    arg = replace_string(arg, YEL, "");
    arg = replace_string(arg, BLU, "");
    arg = replace_string(arg, MAG, "");
    arg = replace_string(arg, CYN, "");
    arg = replace_string(arg, WHT, "");
    arg = replace_string(arg, HIR, "");
    arg = replace_string(arg, HIG, "");
    arg = replace_string(arg, HIY, "");
    arg = replace_string(arg, HIB, "");
    arg = replace_string(arg, HIM, "");
    arg = replace_string(arg, HIC, "");
    arg = replace_string(arg, HIW, "");
    arg = replace_string(arg, NOR, "");
    arg = replace_string(arg, BLINK,"");
    return arg;
}

string clean_color(string arg);
string getwhere(object ob);
string make_color(string map);
string *dirs = ({
	"north",
	"south",
	"east",
	"west",
	"northup",
	"southup",
	"eastup",
	"westup",
	"northdown",
	"southdown",
	"eastdown",
	"westdown",
	"northeast",
	"northwest",
	"southeast",
	"southwest",
	"up",
	"down",
	"enter",
	"out",
});
int main(object me, string arg)
{
	int i, j, jj = 0, k, kk = 0;
	string file,map,name,dest,*search;
	mapping exit1, exit2, exit3;
	object room1, room2, room3, room4;
string *dir2;
	seteuid(getuid());
	if (!arg || arg == "here")
	{
		if( !file = environment(me)->query("outdoors"))
		{
			room1 = environment(me);
			if( mapp(exit1 = room1->query("exits")))
			{
				for (i=0; i<sizeof(dirs); i++)
				{
					if(dest = exit1[dirs[i]])
					{
						if(!(room2 = find_object(dest)))
							room2=load_object(dest);
						if(file=room2->query("outdoors"))
							break;
						else
						{
							if( mapp(exit2 = room2->query("exits")))
							{
								for (j=0; j<sizeof(dirs); j++)
								{
									if(dest = exit2[dirs[j]])
									{
										if(!( room3 = find_object(dest)) )
											room3 = load_object(dest);
										if( file = room3->query("outdoors"))
										{
											jj = 1;
											break; 
										}
										else
											if( mapp(exit3 = room3->query("exits")))
											{
												for (k=0; k<sizeof(dirs); k++)
												{
													if(dest = exit3[dirs[k]])
													{
														if(!( room4 = find_object(dest)) )
															room4 = load_object(dest);
														if( file = room4->query("outdoors"))
														{
															kk = 1;
															break; 
														}
													}
												}
											}
										if (kk == 1)
										{
											jj = 1;
											break;
										}
									}
								}
							}
						}
						if (jj == 1) break;
					}
				}
			}
			if (i==sizeof(dirs))
				return notify_fail(HIG"���ﲻ�ܲ鿴��ͼ���뵽���⡣\n"NOR);
		}
		name = clean_color(environment(me)->query("short"));
if( file_size("/doc/map/" + file)<=0 )
{
dir2=explode(base_name(environment(me)),"/");
file=dir2[1];
}
		if( file_size("/doc/map/" + file)>0 ) 
		{
			if(stringp(map = read_file("/doc/map/" + file)))
			{
				//map = make_color(map);
				map = replace_string(map, name, HIR+name+NOR);
				//me->start_more(map);
				write("$map"+ map + "$#\n");
				return 1;
			}
		}

    if(me->is_busy() )
        return notify_fail("���������̫���ˣ�����Ϣһ�°ɣ�\n");
    if (!me->is_busy()) me->start_busy(3);
		main2(me);
		return notify_fail(HIY"��ʱ��û�п�������ĵ�ͼ��ѯ��ֻ���ṩ��ʱ��ͼ��ѯ��\n"NOR);
	}
	else
	{
		if( file_size("/doc/map/" + arg)>0 ) 
		{
			if(stringp(map = read_file("/doc/map/" + arg)))
			{
//				map = make_color(map);
				//me->start_more(map);
				write("$map"+ map + "$#\n");
				return 1;
			}
		}
		return notify_fail(HIR"û����ָ���ĵ�ͼ��ѯ����help maps��ѯ��ͼ�ᡣ\n"NOR);
	}
}
string clean_color(string arg)
{
	if(!arg) return "";
	arg = replace_string(arg, BLK, "");
	arg = replace_string(arg, RED, "");
	arg = replace_string(arg, GRN, "");
	arg = replace_string(arg, YEL, "");
	arg = replace_string(arg, BLU, "");
	arg = replace_string(arg, MAG, "");
	arg = replace_string(arg, CYN, "");
	arg = replace_string(arg, WHT, "");
	arg = replace_string(arg, HIR, "");
	arg = replace_string(arg, HIG, "");
	arg = replace_string(arg, HIY, "");
	arg = replace_string(arg, HIB, "");
	arg = replace_string(arg, HIM, "");
	arg = replace_string(arg, HIC, "");
	arg = replace_string(arg, HIW, "");
	arg = replace_string(arg, NOR, "");
	arg = replace_string(arg, BLINK,"");
	return arg;
}

string make_color(string map)
{
	map = replace_string(map, "��", HIR"��"NOR);
	map = replace_string(map, "��", HIC"��"NOR);
	map = replace_string(map, "��", HIC"��"NOR);
	map = replace_string(map, "��", HIG"��"NOR);
	map = replace_string(map, "��", GRN"��"NOR);
	map = replace_string(map, "��", HIR"��"NOR);
	map = replace_string(map, "��", HIM"��"NOR);
	map = replace_string(map, "��", HIG"��"NOR);
	map = replace_string(map, "��", YEL"��"NOR);
	map = replace_string(map, "��", YEL"��"NOR);
	map = replace_string(map, "��", HIW"��"NOR);
	map = replace_string(map, "��", MAG"��"NOR);
	map = replace_string(map, "��", HIY"��"NOR);
	map = replace_string(map, "��", HIY"��"NOR);
	map = replace_string(map, "��", HIY"��"NOR);
	map = replace_string(map, "��", HIY"��"NOR);
	map = replace_string(map, "��", HIY"��"NOR);
	map = replace_string(map, "��", HIY"��"NOR);
	map = replace_string(map, "��", HIY"��"NOR);
	map = replace_string(map, "��", HIY"��"NOR);
	map = replace_string(map, "��", HIY"��"NOR);
	map = replace_string(map, "��", HIY"��"NOR);
	map = replace_string(map, "��", HIY"��"NOR);
	map = replace_string(map, "��", HIY"��"NOR);
	map = replace_string(map, "��", HIY"��"NOR);
	map = replace_string(map, "��", HIY"��"NOR);
	map = replace_string(map, "��", HIY"��"NOR);
	map = replace_string(map, "��", HIY"��"NOR);
	map = replace_string(map, "��", HIY"��"NOR);
	map = replace_string(map, "��", HIY"��"NOR);
	map = replace_string(map, "��", HIY"��"NOR);
	map = replace_string(map, "-", HIY"-"NOR);
	map = replace_string(map, "~", HIC"~"NOR);
	map = replace_string(map, "|", HIC"|"NOR);
	map = replace_string(map, "@", HIW"@"NOR);
	map = replace_string(map, "*", GRN"@"NOR);
	map = replace_string(map, "<", GRN"<");
	map = replace_string(map, ">", ">"NOR);
	map = replace_string(map, "��", YEL"��");
	map = replace_string(map, "��", "��"NOR);
	map = replace_string(map, "��", CYN"��"NOR);
	map = replace_string(map, "��", CYN"��"NOR);
	return map;
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

if (dir2[1]=="taiping" )  
{
	output="̫ƽ��";	
}

if (dir2[1]=="eren/eren2" || dir2[1]=="eren" )  
{
	output="���˹�";	
}
return output;
}


int main2(object me)
{
    object where;
    int i,j,k,l,n,p;
    int lineu,lined,linef;
    string *text;
    string tmp;



        X=MinX;
        Y=MinY;


    tmp="�ʱ��ͼv2.0 (by zjpwxh) 2004/4/24 ���ͼ��С��"+X+"/"+Y+"\n\n";
    m=allocate(2*X+1);
    data=allocate((2*X+1)*(2*Y+1));
    rfile=({});
    for(i=0;i<2*X+1;i++)
    {
        m[i]=allocate(2*Y+1);
        for(j=0;j<2*Y+1;j++)
              m[i][j]=" ";
    }

    where=environment(me);
    if(!objectp(where))
        return notify_fail("�Բ��𣬲�֪���㵽��������ѽ������ʦ�ɣ�\n");

    draw_room((2*X+1)/2,(2*Y+1)/2,where);

    for(l=0,linef=1;l<2*Y+1;l++)
    {
        for(n=0;n<2*X+1;n++)
        {
              if( m[n][l]!=" ")
                  p++;
        }
        if(!p && linef)
        {
              lineu++;
              linef=1;
        }
        else     linef=0;
        p=0;
    }
    for(l=2*Y,linef=1;l>=0;l--)
    {
        for(n=0;n<2*X+1;n++)
        {
              if( m[n][l]!=" ")
                  p++;
        }
        if(!p && linef)
        {
              lined++;
              linef=1;
        }
        else     linef=0;
        p=0;
    }

    for(i=lineu;i<2*Y+1-lined;i++)
    {
        for(j=0;j<2*X+1;j++)
        {
              if( m[j][i]==" " && i%2 && j%2 )
                  tmp+="     ";
              else
              {
                  //�������Ϊ�գ����Ҵ�ʱjΪż���У�������ո�
                  if( m[j][i]==" " && !(j%2) )
                      tmp+=" ";
                  else
                  {
                      if( m[j][i]==" " )
                            tmp+="     ";

                      else
                            tmp+=m[j][i];
                  }
              }
        }
        tmp+="\n";
    }
    text=explode(tmp, "\n");
    for(i=k; k<sizeof(text); k++)
        write(text[k] + "\n");

    return 1;
}

object find_room(string path)
{
    object ob;
    if( objectp(ob=find_object(path)) || objectp(ob=load_object(path)) )
        return ob;
    return 0;
}

//���������I�J�K�L
int draw_path(int x,int y,string direc)
{
    string str;
    int xx=0,yy=0;
    switch(direc)
    {
        case "south":
        case "north":         str="   ��   ";break;
        case "southdown":
        case "northup":         str="   ��   ";break;
        case "southup":
        case "northdown":     str="   ��   ";break;
        case "east":
        case "west":         str="��";break;
        case "eastup":
        case "westdown":     str="��";break;
        case "westup":
        case "eastdown":     str="��";break;
        case "southeast":
        case "northwest":     str="�K";break;
        case "southwest":
        case "northeast":     str="�J";break;
        default:
              return 0;
    }
    if(sscanf(direc,"%*ssouth%*s"))
        yy++;
    if(sscanf(direc,"%*snorth%*s"))
        yy--;
    if(sscanf(direc,"%*seast%*s"))
        xx++;
    if(sscanf(direc,"%*swest%*s"))
        xx--;
    if( x+xx<=0 || y+yy<=0 || x+xx>=2*X || y+yy>=2*Y )
        return 0;
    m[x+xx][y+yy]=HIW+str+NOR;
    return 1;
}

// ���ù�ȱ���Ѱ·�㷨,ʹ��ͼ����ʾ���Ӻ���
int draw_room(int x,int y,object room)
{
    int i,xx,yy;
    int front,rear;
    string *dirs;
    object froom,nroom;
    mapping dir,x_y;
    object *queue;
    front=0;rear=0;

    queue=allocate( (2*X+1)*(2*Y+1) );
    reset_eval_cost();
    if( x<0 || y<0 || !objectp(room) || x>2*X || y>2*Y )
        return 0;

    rfile=rfile + ({ base_name(room) });
    queue[rear]=room;
    set_room(x,y,room);
    set_x_y(x,y,rear);
    rear++;

    while( front < rear )
    {
        reset_eval_cost();
        froom=queue[front];
        x_y=data[front];
        front++;
        dir=froom->query("exits");
        if( !mapp(dir) || sizeof(dir)<1 )
              return 0;
        dirs=keys(dir);
              for(i=0;i<sizeof(dirs);i++)
        {
                    nroom=find_room(dir[dirs[i]]);
                    if(!objectp(nroom) || member_array(base_name(nroom),rfile)!=-1)
                        continue;
                    xx=0;yy=0;
              if( sscanf(dirs[i],"%*ssouth%*s"))
                  yy+=2;
              if( sscanf(dirs[i],"%*snorth%*s"))
                  yy-=2;
              if( sscanf(dirs[i],"%*seast%*s"))
                  xx+=2;
              if( sscanf(dirs[i],"%*swest%*s"))
                  xx-=2;
              if( x_y["xst"]+xx<0 || x_y["yst"]+yy<0 || x_y["xst"]+xx>2*X || x_y["yst"]+yy>2*Y )
                  continue;
              if( m[x_y["xst"]+xx][x_y["yst"]+yy]!=" ")
                  continue;
              if( !draw_path(x_y["xst"],x_y["yst"],dirs[i]) || (xx==0&&yy==0))
                  continue;
              rfile=rfile + ({ base_name(nroom) });
              queue[rear]=nroom;
              set_room(x_y["xst"]+xx,x_y["yst"]+yy,nroom);
              set_x_y(x_y["xst"]+xx,x_y["yst"]+yy,rear);
              rear++;
        }
    }
}

void set_room(int x,int y,object room)
{
    int i,d,xx,yy,flag;
    string name;
    mapping dir;
    string *dirs;

    // ��ȡ����ɫ�ķ���short����
    name=clean_color(room->query("short"));

    // ����Ķ����������4����������
    if(strlen(name)>8) name=name[0..7];

    if(strlen(name)<7) //�Բ���4�����ֵķ��������о��д���
    {
        d=8-strlen(name);
        if( d%2 )
        {
              name+=" ";
              d--;
        }
        for(i=0;i<d/2;i++)
              name=" "+name+" ";
    }

    dir=room->query("exits");
    if( !mapp(dir) || sizeof(dir)<1 )
        flag=1;
    dirs=keys(dir);
    for(i=0;i<sizeof(dirs);i++)
    {
        xx=0;yy=0;
        if( sscanf(dirs[i],"%*ssouth%*s"))
              yy+=2;
        if( sscanf(dirs[i],"%*snorth%*s"))
              yy-=2;
        if( sscanf(dirs[i],"%*seast%*s"))
              xx+=2;
        if( sscanf(dirs[i],"%*swest%*s"))
              xx-=2;
        if( xx==0 && yy==0 )
              flag=1;
    }

    if( flag ) name=HIY+name;
    if((x==(2*X+1)/2)&&(y==(2*Y+1)/2))
        name=BLINK+HIC+name;
    name+=NOR;
    m[x][y]=name;
}

void set_x_y(int x,int y,int rear)
{
    data[rear]=([
        "xst":x,
        "yst":y,
    ]);
}


int help(object me)
{
	write(@HELP
ָ���ʽ��map <����>

    ���ָ��������ʾָ���ĵ�ͼ����ͼ�ᣬ����help maps��ѯ��
    ������������Ĳ�����here������ʾ�����ڵصĵ�ͼ������ɫ��ʾ����
��֮�ء�

HELP
	);
	return 1;
}

