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
	      set_name("[1;34m»Õ÷Æ ÷Ã◊[2;37;0m", ({ "bad hands", "hands" }));
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "∏±");
		set("long", @LONG
»Õ÷Æ ÷Ã◊[2;37;0m’‚ «“ª∏±”… Æ∑÷º·”≤µƒæ´∏÷º”…œ[1;37m√ﬁª®[2;37;0m÷∆≥…£¨÷ÿ¡„ΩÔæ≈¡Ω∆ﬂ«Æµƒ[1;34m»Õ÷Æ ÷Ã◊[2;37;0m°£
◊€∫œ∆¿º€[32mæ´÷¬œ∏√¿[2;37;0m ø¥∆¿¥ Æ∑÷º·πÃ£¨æﬂ”–[36m“ª∞„[2;37;0mµƒ∑¿ª§¡¶£°
…œ√ÊøÃ¡Àº∏∏ˆπ≈∑˚∫≈£∫
[1;34mµÁ[2;37;0m:[32m¥÷≤⁄[2;37;0m [40mµÿ[2;37;0m:[35m±Í◊º[2;37;0m 
…œ√ÊªπøÃ¡À“ª–©∑˚◊÷£∫
º·”≤:[34mœ∏ÀÈ[2;37;0m ∏£‘¥:[32mº´≤Ó[2;37;0m 
«…÷∆:[32mº´≤Ó[2;37;0m 
≤ª¿œ:[33m“ª∞„[2;37;0m Õ˛¡¶:[33m“ª∞„[2;37;0m 

LONG
);
    set("no_get",1);
	  set("no_put",1);
	  set("no_pawn",1);
	  set("no_drop",1);
	  set("no_beg",1);
	  set("no_steal",1);
	  set("systemmake",1);
		set("value", 2000);
		set("armor_prop/intelligence",0);
		set("armor_prop/strength",0);
		set("armor_prop/karey",5);
		set("armor_prop/percao",0);
		set("armor_prop/dexerity",0);
		set("armor_prop/constitution",0);
    set("armor_prop/dodge", 0);
    set("armor_prop/parry", 0);
    set("armor_prop/attack", 0);


    set("armor_prop/armor", 14);
    set("armor_prop/defense", 0);
    
    set("armor_prop/neili", 0);
    set("armor_prop/qi", 0);
    set("armor_prop/jing", 9);
    set("armor_prop/jingli", 9);
    set("armor_prop/damage", 122);

    set("wtypeA",0);
    set("wtypeB",0);
    set("wtypeC",0);
    set("wtypeD",0);
    set("wtypeE",0);
    set("wtypeF",0);
    set("wtypeG",0);
    set("wtypeH",3);
    set("wtypeI",0);
    set("wtypeJ",5);
    set("wtypeK",0);
    set("wtypeL",0);
    
    
                set("skill", ([
                        "name": "cuff",
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



#include "/obj/ritem/armorzy.h";