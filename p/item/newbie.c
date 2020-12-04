#include <ansi.h> 
#include <armor.h>

inherit ARMOR;

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
"qx_snake_poison",
"anqi_poison",
"yf_poison",
"nx_poison",
"chilian_poison",
"yufeng_poison",
"insect_poison",
"xscold_poison",
});

string *order = ({""HIY"", ""HIG"", ""RED"", ""MAG"", ""YEL"", ""HIC"", ""HIW"", ""HIR"",""HIB"", ""CYN"",""WHT"",""HIM"",""BLU""});  
void create()
{
	      set_name("[1;32mĞÂÊÖÖ®Åû·ç[2;37;0m¡ï", ({ "newbie armor", "armor" }));
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "¼ş");
		set("long", @LONG
[1;32mĞÂÊÖÖ®Åû·ç[2;37;0mÕâÊÇÒ»¼şÓÉÎŞ±È¼áÓ²µÄ¾«¸Ö¼ÓÉÏ[1;33mÜÑÂé[2;37;0mÖÆ³É£¬ÖØÒ»½ïÁãÁ½¾ÅÇ®µÄ[1;32mĞÂÊÖÖ®Åû·ç[2;37;0m¡£
×ÛºÏÆÀ¼Û[37m¾øÊÀÎŞË«[2;37;0m ¿´ÆğÀ´ÎŞ±È¼á¹Ì£¬¾ßÓĞ[36m²»Ğ¡[2;37;0mµÄ·À»¤Á¦£¡
ÕâÊÇÒ»¼şÌØÊâµÄÎïÆ· ÊôĞÔÈçÏÂ:
ÌìÁé:[1;32mÒ»°ã[2;37;0m °×Ê¯:[1;32m¼«²î[2;37;0m ×ÏÊ¯:[1;32m¼«²î[2;37;0m
ÉÁµç:[1;32m¼«²î[2;37;0m ÇÉÖÆ:[1;32mÃğÊÀ[2;37;0m ÌåÁé:[1;32m¼«²î[2;37;0m  ³¤Éú:[1;32m¼«²î[2;37;0m ²»ÀÏ:[1;32m¼«²î[2;37;0m ²»Ãğ:[1;32m¼«²î[2;37;0m 
ÕâÊÇÒ»¼ş´òÔìµÄÎïÆ· ·û×ÖÈçÏÂ:
Ë®:[1;32m²»´í[2;37;0m ·ç:[1;32m²»´í[2;37;0m µØ:[1;32m²»´í[2;37;0m 
ÉÏÃæ¿Ì×Å ¿ÉÒÔÑ§Ï°µÄÎä¹¦ ¶ÁÊéĞ´×Ö (literate)
LONG
);
    set("no_get",1);
	  set("no_put",1);
	  set("no_pawn",1);
	  set("no_give",1);
	  set("no_drop",1);
	  set("no_beg",1);
	  set("no_steal",1);
	  set("systemmake",1);
		set("value", 1800);
		set("armor_prop/intelligence",6);
		set("armor_prop/strength",0);
		set("armor_prop/karey",0);
		set("armor_prop/percao",0);
		set("armor_prop/dexerity",0);
		set("armor_prop/constitution",0);
    set("armor_prop/dodge", 2);
    set("armor_prop/parry", 2);
    set("armor_prop/attack", 2);


    set("armor_prop/armor", 200);
    set("armor_prop/defense", 2);
    
    set("armor_prop/neili", 0);
    set("armor_prop/qi", 3);
    set("armor_prop/jing", 3);
    set("armor_prop/jingli", 3);
    set("armor_prop/damage", 0);

    set("wtypeA",0);
    set("wtypeB",0);
    set("wtypeC",1);
    set("wtypeD",0);
    set("wtypeE",0);
    set("wtypeF",1);
    set("wtypeG",0);
    set("wtypeH",0);
    set("wtypeI",0);
    set("wtypeJ",1);
    set("wtypeK",0);
    set("wtypeL",0);
    
    
                set("skill", ([
                        "name": "literate",
                        "exp_required": 80000,
                        "difficulty": 85,
                        "min_skill":  1,
                        "max_skill": 80,              
                ]) );		


		set("material", "default");
    set("sharpness", 12);
        }
        setup();
}



#include "/obj/ritem/armorzy.h";