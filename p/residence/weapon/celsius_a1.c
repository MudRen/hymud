#include <ansi.h> 
#include <armor.h>

inherit HANDS;

string *du=({
"ice_poison",
"ill_dongshang",
"ill_fashao",
"ill_kesou",
"ill_shanghan",
"ill_zhongshu",
"xx_poison",
"cold_poison",
"flower_poison",
"rose_poison",
"x2_poison",
"sanpoison",
"scorpion_poison",
"anqi_poison",
"nx_poison",
"chilian_poison",
"yufeng_poison",
"insect_poison",
"xscold_poison",
});

string *order = ({""HIY"", ""HIG"", ""RED"", ""MAG"", ""YEL"", ""HIC"", ""HIW"", ""HIR"",""HIB"", ""CYN"",""WHT"",""HIM"",""BLU""});  
void create()
{
	      set_name("[1;33mHガントレット[2;37;0m", ({ "bad hands", "hands" }));
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "険");
		set("long", @LONG
窈岻返耗[2;37;0m宸頁匯険喇自葎釈啣議[32m楳有[2;37;0m紗貧[1;37m筑雑[2;37;0m崙撹��嶷匯緒匯曾匯熱議[1;33m窈岻返耗[2;37;0m。
忝栽得勺[32m娼崑聾胆[2;37;0m 心軟栖自葎釈耕��醤嗤[36m匯違[2;37;0m議契擦薦��
貧中震阻叱倖硬憲催��
[1;33m署[2;37;0m:[32m間華[2;37;0m 
貧中珊震阻匯乂憲忖��
釈啣:[34m聾哩[2;37;0m 爺圜:[32m自餓[2;37;0m 派崙:[32m自餓[2;37;0m 
易墳:[32m自餓[2;37;0m 璃薦:[32m自餓[2;37;0m 
參式匯電硬廰忖‐ [1;32m毘其俐帽[2;37;0m ／。才匯乂‐ [1;32m坪孔[2;37;0m ／議室派。

LONG
);
			set("no_get",1);
	set("no_drop",1);
	set("no_put",1);
	set("no_beg",1);
	set("no_steal",1);
	set("ownmake",1);
		set("makeritem",1);
		set("owner", "celsius");
		set("ownername", "毘其俐帽");
		set("value", 2000);
		set("armor_prop/intelligence",0);
		set("armor_prop/strength",0);
		set("armor_prop/karey",0);
		set("armor_prop/percao",0);
		set("armor_prop/dexerity",2);
		set("armor_prop/constitution",0);
    set("armor_prop/dodge", 4);
    set("armor_prop/parry", 0);
    set("armor_prop/attack", 0);


    set("armor_prop/armor", 14);
    set("armor_prop/defense", 0);
    
    set("armor_prop/neili", 0);
    set("armor_prop/qi", 0);
    set("armor_prop/jing", 0);
    set("armor_prop/jingli", 0);
    set("armor_prop/damage", 221);

    set("wtypeA",3);
    set("wtypeB",0);
    set("wtypeC",0);
    set("wtypeD",0);
    set("wtypeE",0);
    set("wtypeF",0);
    set("wtypeG",0);
    set("wtypeH",0);
    set("wtypeI",0);
    set("wtypeJ",0);
    set("wtypeK",0);
    set("wtypeL",0);
    
    
                set("skill", ([
                        "name": "force",
                        "exp_required": 80000,
                        "difficulty": 85,
                        "min_skill":  1,
                        "max_skill": 50,              
                ]) );		


		set("material", "default");
    set("sharpness", 2);
        }
        setup();
}

int query_autoload() { return 1; }

#include "/obj/armorzy.h";