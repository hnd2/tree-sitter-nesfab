package tree_sitter_nesfab_test

import (
	"testing"

	tree_sitter "github.com/smacker/go-tree-sitter"
	"github.com/tree-sitter/tree-sitter-nesfab"
)

func TestCanLoadGrammar(t *testing.T) {
	language := tree_sitter.NewLanguage(tree_sitter_nesfab.Language())
	if language == nil {
		t.Errorf("Error loading Nesfab grammar")
	}
}
